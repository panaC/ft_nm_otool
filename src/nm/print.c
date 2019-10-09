/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/09 20:11:56 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <ft_printf.h>
#include "common.h"

char			type_char(void *ptr, t_nlist *list)
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
		ft_printf("sect:%d\n", GET(list, n_sect));
		return ('p');
		if (ptr)
		{
			//hello
		}
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
	while (i < nb_symb)
	{
		// n_un
		// A union that holds an index into the string table, n_strx. To specify an empty string (""), set this value to 0. The n_name field is not used in Mach-O files.

		// needed ptr to calcul size
		if (GETI(list, sorted_array[i], n_value))
			ft_printf("%0.8x%0.8x %c %s\n",
					GETI(list, sorted_array[i], n_value) >> 32,
					GETI(list, sorted_array[i], n_value),
					type_char(ptr, GEI(list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
		else
			ft_printf("%16c %c %s\n", ' ',
					type_char(ptr, GEI(list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
		++i;
	}
	return (0);
}
