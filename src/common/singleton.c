/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:00:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/11 22:33:52 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "common.h"

int			s_swap(t_boo state)
{
	static t_boo	value = false;

	if (state != undef)
		value = state;
	return (value);
}

int			s_b64(t_boo state)
{
	static t_boo	value = false;

	if (state != undef)
	{
		value = state;
		// ft_printf("b64:%d\n", value);
	}
	return (value);
}

int			s_size(int size)
{
	static int		value = 0;

	if(size != undef)
	{
		value = size;
	}
	return (value);
}

char		*s_array(char *data, uint8_t i, int mode)
{
	static char		*value[1000];

	if (i >= 1000)
		return (NULL);
	if (mode == 1)
		return ((value[i] = data));
	if (mode == 0)
		return (value[i]);
	return (NULL);
}
