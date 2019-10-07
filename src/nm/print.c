/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/06 22:05:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <ft_printf.h>
#include "common.h"

char			type_char(t_nlist *list)
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
		return ('p');
	}
	return ('S');
}

int				nm_print(t_nlist_p list, uint32_t *sorted_array,
		uint32_t nb_symb, void *stroff)
{
	uint32_t	i;

	i = 0;
	while (i < nb_symb)
	{

		// needed ptr to calcul size
		if (GETI(list, sorted_array[i], n_value))
			ft_printf("%0.8x%0.8x %c %s\n",
					GETI(list, sorted_array[i], n_value) >> 32,
					GETI(list, sorted_array[i], n_value),
					type_char(GEI(list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
		else
			ft_printf("%16c %c %s\n",
					' ',
					type_char(GEI(list, sorted_array[i])),
					GETI(stroff + list, sorted_array[i], n_un.n_strx));
		++i;
	}
	return (0);
}
