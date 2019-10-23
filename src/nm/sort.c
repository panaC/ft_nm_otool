/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:06:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/23 23:37:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>
#include <mach-o/nlist.h>
#include "common.h"

static uint32_t		*init_sort_array(uint32_t *array, uint32_t n)
{
	uint32_t		i;

	i = 0;
	while (i < n)
	{
		array[i] = i;
		++i;
	}
	return (array);
}

int			swap(uint32_t *a, uint32_t *b)
{
	uint32_t		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

void				sort_array(void *ptr, uint32_t *array,
		struct symtab_command *symtab)
{
	int				flag;
	uint32_t		i;
	t_nlist_p		l;
	void			*le;
	void			*ri;

	l = (t_nlist_p)(struct nlist*)(ptr + symtab->symoff);
	init_sort_array(array, symtab->nsyms);
	if (!s_a_not_sort(UN))
	{
		flag = 1;
		while (flag)
		{
			flag = 0;
			i = 0;
			while (i < symtab->nsyms - 1)
			{
				le = ptr + symtab->stroff + GETI(l, array[i], n_un.n_strx);
				ri = ptr + symtab->stroff + GETI(l, array[i + 1], n_un.n_strx);
				if (SIZE(ptr, le) && SIZE(ptr, ri) && SORT(ft_strcmp(le, ri)))
					flag = swap(array + i, array + i + 1);
				++i;
			}
		}
	}
}
