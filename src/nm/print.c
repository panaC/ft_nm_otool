/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/24 23:46:18 by pleroux          ###   ########.fr       */
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
	if ((GET(list, n_type) & N_TYPE) == N_SECT &&
			s_array(NULL, GET(list, n_sect), 0))
	{
		//ft_printf("-> '%s':%d\n", s_array(NULL, GET(list, n_sect), 0), GET(list, n_sect));
		if (!ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SECT_DATA, 16) ||
				!ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SEG_DATA, 16))
			return ('D');
		if (!ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SECT_BSS, 16))
			return ('B');
		if (!ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SECT_TEXT, 16) ||
				!ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SEG_TEXT, 16))
			return ('T');
		//if (ft_strncmp(s_array(NULL, GET(list, n_sect), 0), SECT_COMMON, 16) == 0)
		//	return ('C');
	}
	return ('S');
}

static char		type_char_extern(t_nlist *list)
{
	if ((GET(list, n_type) & N_EXT) == 0)
		return (ft_tolower(type_char(list)));
	return (type_char(list));
}

void			print_32_64(char **string_ptr,
		uint64_t nvalue, char c, char *name)
{
	if (s_b64(UN))
	{
		if (!nvalue)
			ft_sprintf(string_ptr, "%16c %c %s\n", ' ',
					c,
					name);
		else
			ft_sprintf(string_ptr, "%0.8x%0.8x %c %s\n",
					nvalue >> 32,
					nvalue,
					c,
					name);
	}
	else
	{
		if (!nvalue)
			ft_sprintf(string_ptr, "%8c %c %s\n", ' ',
					c,
					name);
		else
			ft_sprintf(string_ptr, "%0.8x %c %s\n",
					nvalue,
					c,
					name);
	}
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
		/*
		t_nlist *t = GEI(t_nlist*, list, i);
		if ((GET(t, n_type) & N_TYPE) == N_SECT &&
			s_array(NULL, GET(t, n_sect), 0))
			ft_printf("%s %d\n", GETI(stroff + list, i, n_un.n_strx),
				GET(t, n_sect));
				*/
		if (GETI(list, i, n_type) & N_STAB && !s_a_disp(UN))
			continue ;
		print_32_64(&(string_array[i]),
				GETI(list, i, n_value),
				type_char_extern(GEI(t_nlist*, list, i)),
				GETI(stroff + list, i, n_un.n_strx));
	}
}

void			nm_print(void *ptr, char **string_array, uint32_t *sorted_array,
		struct symtab_command *symtab)
{
	uint32_t	i;
	uint32_t	c;

	c = s_b64(UN) ? 19 : 11;
	i = 0;
	while (i < symtab->nsyms - 1 && SIZE(ptr, (void*)symtab + symtab->cmdsize))
	{
		if (ft_strlen(string_array[sorted_array[i]]) > c &&
				ft_strlen(string_array[sorted_array[i + 1]]) > c &&
				ft_strcmp(string_array[sorted_array[i]] + c,
					string_array[sorted_array[i + 1]] + c) == 0 &&
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
