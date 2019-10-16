/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:06:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/16 21:16:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>
#include <mach-o/nlist.h>
#include "common.h"

static void			swap(uint32_t *a, uint32_t *b)
{
	uint32_t		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

void				sort_array(uint32_t *array, void *off, t_nlist_p l, uint32_t n)
{
	int				flag;
	uint32_t		i;

	init_sort_array(array, n);
	if (!s_a_not_sort(UN))
	{
		flag = 1;
		while (flag)
		{
			flag = 0;
			i = 0;
			while (i < n - 1)
			{
				if (SORT(ft_strcmp(off + GETI(l, array[i], n_un.n_strx),
								off + GETI(l, array[i + 1], n_un.n_strx))))
				{
					swap(array + i, array + i + 1);
					flag = 1;
				}
				++i;
			}
		}
	}
}
