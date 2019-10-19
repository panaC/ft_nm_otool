/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 15:54:15 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "common.h"

static void	print_hex(unsigned char hex)
{
	char	*tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[hex / 16]);
	ft_putchar(tab[hex % 16]);
}

static void	make_hexs(unsigned char *line, size_t remain)
{
	size_t	i;

	i = 0;
	while (i < 16 && i < remain)
	{
		print_hex(line[i]);
		if (i < 16 && i < remain)
			ft_putchar(' ');
		i++;
	}
}

void		otool_print_memory(const void *addr, size_t size, uint64_t address)
{
	unsigned char	*tmp;
	int				remain;

	tmp = (unsigned char*)addr;
	remain = size - (size_t)((void*)tmp - addr);
	while (remain > 0)
	{
		if (s_b64(UN))
			ft_printf("%0.8x", address >> 32);
		ft_printf("%0.8x\t", address);
		make_hexs(tmp, remain);
		ft_putchar('\n');
		tmp += 16;
		remain = size - (size_t)((void*)tmp - addr);
		address += 0x10;
	}
}
