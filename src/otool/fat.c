/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:54:22 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 16:55:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <mach/machine.h>
#include <mach-o/fat.h>
#include "common.h"
#include <ft_printf.h>

int			otool_fat(void *ptr)
{
	uint32_t			nb_fatarch;
	struct fat_arch		*arch;

	nb_fatarch = ((struct fat_header*)ptr)->nfat_arch;
	arch = (struct fat_arch*)(ptr + sizeof(struct fat_header));
	while (nb_fatarch--)
	{
		if (swap_int32(arch->cputype) == CPU_TYPE_X86_64)
			return (otool_macho(ptr + swap_uint32(arch->offset)));
		++arch;
	}
	return (EXIT_FAILURE);
}
