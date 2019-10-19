/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:06:45 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 16:02:14 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint16_t		swap_uint16(uint16_t val)
{
	return ((val << 8) | (val >> 8));
}

int16_t			swap_int16(int16_t val)
{
	return ((val << 8) | ((val >> 8) & 0xFF));
}

uint32_t		swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

int32_t			swap_int32(int32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | ((val >> 16) & 0xFFFF));
}
