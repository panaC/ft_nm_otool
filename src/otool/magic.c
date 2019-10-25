/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:44:14 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/25 15:55:14 by pleroux          ###   ########.fr       */
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
		ft_printf("The file was not recognized as a valid object file.\n");
	if (*(uint32_t *)ptr == MH_MAGIC)
		return (otool_macho(ptr));
	if (*(uint32_t *)ptr == MH_CIGAM)
		ft_printf("The file was not recognized as a valid object file.\n");
	if (*(uint32_t *)ptr == FAT_MAGIC)
		ft_printf("The file was not recognized as a valid object file.\n");
	if (*(uint32_t *)ptr == FAT_MAGIC_64)
		ft_printf("The file was not recognized as a valid object file.\n");
	if (*(uint32_t *)ptr == FAT_CIGAM)
		return (otool_fat(ptr));
	if (*(uint32_t *)ptr == FAT_CIGAM_64)
		ft_printf("The file was not recognized as a valid object file.\n");
	if (ft_strncmp((char *)ptr, ARMAG, SARMAG) == 0)
		ft_printf("The file was not recognized as a valid object file.\n");
	return (0);
}
