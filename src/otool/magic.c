/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:44:14 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 16:57:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <ar.h>
#include "common.h"
#include <ft_printf.h>

int					otool_magic(void *ptr)
{
	if (*(uint32_t *)ptr == MH_MAGIC_64)
		return (otool_macho(ptr));
	if (*(uint32_t *)ptr == MH_CIGAM_64)
		ft_printf("macho64-inv\n");
	if (*(uint32_t *)ptr == MH_MAGIC)
		return (otool_macho(ptr));
	if (*(uint32_t *)ptr == MH_CIGAM)
		ft_printf("macho-inv\n");
	if (*(uint32_t *)ptr == FAT_MAGIC)
		ft_printf("fat-32");
	if (*(uint32_t *)ptr == FAT_MAGIC_64)
		ft_printf("fat-64");
	if (*(uint32_t *)ptr == FAT_CIGAM)
		return (otool_fat(ptr));
	if (*(uint32_t *)ptr == FAT_CIGAM_64)
		ft_printf("fat-64 inv");
	if (ft_strncmp((char *)ptr, ARMAG, SARMAG) == 0)
		ft_printf("arch");
	return (0);
}
