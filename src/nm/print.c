/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/23 23:51:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <ft_printf.h>
#include "common.h"

static char		type_char(t_nlist *list)
{
	if ((GET(list, n_type) & N_TYPE) == N_UNDF)
		return ('U');
	if ((GET(list, n_type) & N_TYPE) == N_ABS)
		return ('A');
	if ((GET(list, n_type) & N_TYPE) == N_PBUD)
		return ('S');
	if ((GET(list, n_type) & N_TYPE) == N_INDR)
		return ('I');
	if ((GET(list, n_type) & N_TYPE) == N_SECT)
	{
		if (!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SECT_DATA) ||
				!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SEG_DATA))
			return ('D');
		if (!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SECT_BSS))
			return ('B');
		if (!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SECT_TEXT) ||
				!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SEG_TEXT))
			return ('T');
		if (!ft_strcmp(s_array(NULL, GET(list, n_sect), 0), SECT_COMMON))
			return ('C');
	}
	return ('S');
}

static char		type_char_extern(t_nlist *list)
{
	if ((GET(list, n_type) & N_EXT) == 0)
		return (ft_tolower(type_char(list)));
	return (type_char(list));
}

void			nm_print_buffer(void *ptr, char **string_array,
		struct symtab_command *symtab)
{
	uint32_t	i;
	t_nlist_p	list;
	uint32_t	nb_symb;
	void		*stroff;

	stroff = ptr + symtab->stroff;
	nb_symb = symtab->nsyms;
	list = (t_nlist_p)(struct nlist*)(ptr + symtab->symoff);
	i = -1;
	while ((++i) < nb_symb &&
		SIZE(ptr, GETI(stroff + list, i, n_un.n_strx)))
	{
		if (GETI(list, i, n_type) & N_STAB && !s_a_disp(UN))
			continue ;
		if (GETI(list, i, n_value))
			ft_sprintf(&(string_array[i]), "%0.8x%0.8x %c %s\n",
					GETI(list, i, n_value) >> 32,
					GETI(list, i, n_value),
					type_char_extern(GEI(t_nlist*, list, i)),
					GETI(stroff + list, i, n_un.n_strx));
		else
			ft_sprintf(&(string_array[i]), "%16c %c %s\n", ' ',
					type_char_extern(GEI(t_nlist*, list, i)),
					GETI(stroff + list, i, n_un.n_strx));
	}
}

void			nm_print(char **string_array, uint32_t *sorted_array,
		struct symtab_command *symtab)
{
	uint32_t	i;
	uint32_t	c;

	c = s_b64(UN) ? 17 : 9;
	i = 0;
	while (i < symtab->nsyms - 1)
	{
		if (ft_strcmp(string_array[sorted_array[i]] + c + 2,
					string_array[sorted_array[i + 1]] + c + 2) == 0 &&
				ft_strcmp(string_array[sorted_array[i]],
				string_array[sorted_array[i + 1]]) > 0)
			swap(sorted_array + i, sorted_array + i + 1);
		ft_putstr(string_array[sorted_array[i]]);
		free(string_array[sorted_array[i]]);
		++i;
	}
	ft_putstr(string_array[sorted_array[i]]);
	free(string_array[sorted_array[i]]);
	free(string_array);
}
