/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:14:45 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/22 17:45:14 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <mach/machine.h>
#include <mach-o/fat.h>
#include "common.h"
#include <ft_printf.h>

int			nm_fat(void *ptr)
{
	uint32_t			nb_fatarch;
	struct fat_arch		*arch;

	if (SIZE(ptr, (void*)ptr + sizeof(struct fat_header)))
	{
		nb_fatarch = ((struct fat_header*)ptr)->nfat_arch;
		arch = (struct fat_arch*)(ptr + sizeof(struct fat_header));
		while (nb_fatarch--)
		{
			if (SIZE(ptr, (void*)arch + swap_int32(arch->size)))
			{
				if (swap_int32(arch->cputype) == CPU_TYPE_X86_64)
					return (nm_macho(ptr + swap_uint32(arch->offset)));
				++arch;
			}
			else
			{
				ft_printf("truncated or malformed object (fat_arch)\n");
				break;
			}
		}
	}
	else
		ft_printf("truncated or malformed object (fat_header)\n");
	return (EXIT_FAILURE);
}
