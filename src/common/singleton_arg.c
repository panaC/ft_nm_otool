/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:29:39 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 16:00:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int			s_a_disp(t_boo state)
{
	static t_boo	value = false;

	if (state != undef)
		value = state;
	return (value);
}

int			s_a_sort(t_boo state)
{
	static t_boo	value = false;

	if (state != undef)
		value = state;
	return (value);
}

int			s_a_not_sort(t_boo state)
{
	static t_boo	value = false;

	if (state != undef)
		value = state;
	return (value);
}
