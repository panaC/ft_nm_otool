/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/16 20:57:05 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <ft_printf.h>
#include "common.h"

static char		type_char(t_nlist *list)
{
	// ft_printf("%0.2x - %0.2x\n", (list->n_type & N_TYPE), (list->n_sect));
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
		// ft_printf("sect:%d\n", GET(list, n_sect));
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

int				nm_print(void *ptr, uint32_t *sorted_array,
					struct symtab_command *symtab)
{
	uint32_t	i;
	t_nlist_p	list;
	uint32_t	nb_symb;
	void		*stroff;

	stroff = ptr + symtab->stroff;
	nb_symb = symtab->nsyms;
	list = (t_nlist_p)(struct nlist*)(ptr + symtab->symoff);
	i = 0;
	while (i++ < nb_symb)
	{
		// n_un
		// A union that holds an index into the string table, n_strx. To specify an empty string (""), set this value to 0. The n_name field is not used in Mach-O files.

		// needed ptr to calcul size
		if (GETI(list, sorted_array[i], n_type) & N_STAB && !s_a_disp(UN))
			continue ;
		if (GETI(list, sorted_array[i], n_value))
			ft_printf("%0.8x%0.8x %c %s\n",
					GETI(list, sorted_array[i], n_value) >> 32,
					GETI(list, sorted_array[i], n_value),
					type_char(GEI(t_nlist*, list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
		else
			ft_printf("%16c %c %s\n", ' ',
					type_char(GEI(t_nlist*, list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
	}
	return (0);
}
