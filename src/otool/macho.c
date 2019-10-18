/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:47:08 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/18 20:44:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "common.h"

int			section_text(void *ptr, uint32_t offset, uint32_t size)
{
	ft_printf("section text size %d\n", size);
	if (SIZE(ptr, ptr + offset + size))
	{
		// otool_print_memory(ptr + offset, size);
		return (0);
	}

	ft_printf("truncated or malformed object (section_64 __TEXT __text)\n");
	return (EXIT_FAILURE);
}

int			section(void *ptr, t_sect_p sect, uint32_t nsects)
{
	uint32_t		i;

	i = 0;
	// ft_printf("nb segment %d\n", nsects);
	while (i < nsects)
	{
		ft_printf("section: %d %d\n", GETI(sect, i, offset), GETI(sect, i, size));
		if (ft_strncmp(GETI(sect, i, sectname),
				SECT_TEXT, ft_strlen(SECT_TEXT)) == 0)
		{
			ft_printf("section name: %s\n", GETI(sect, i, sectname));
			return (section_text(ptr, GETI(sect, i, offset),
						GETI(sect, i, size)));
		}
		++i;
	}
	ft_printf("__text section missing\n");
	return (EXIT_FAILURE);
}

int			otool_macho_lc(void *ptr, struct load_command *lc)
{
	uint32_t	nb_load_cmd;
	int			ret;

	ret = EXIT_FAILURE;
	nb_load_cmd = s_b64(UN) ? ((struct mach_header_64*)ptr)->ncmds :
		((struct mach_header*)ptr)->ncmds;

	while (nb_load_cmd--)
	{
		if (SIZE(ptr, (void*)lc + lc->cmdsize))
		{
			if (lc->cmd == LC_SEGMENT_64 &&
					ft_strcmp(GET(((t_segcmd*)lc), segname), SEG_TEXT) == 0)
			{
				struct section_64 *t = (void*)lc + sizeof(struct segment_command_64);
				ft_printf("offset %x\n", (void*)t - ptr);
				ft_printf("macho: %s %s %0.8x%0.8x %d %d\n", t->sectname, t->segname, (t->addr >> 32), t->addr, t->offset, t->size);
				ft_print_memory(lc, lc->cmdsize);
				return (section(ptr,
					(t_sect_p)(struct section*)((void*)lc + (s_b64(UN) ?
						sizeof(struct segment_command_64) : sizeof(struct segment_command))),
					GET(((t_segcmd*)lc), nsects)));
			}
			lc = (struct load_command*)((void*)lc + lc->cmdsize);
		}
		else
			break ;
	}
	ft_printf("truncated or malformed object (symtab_command)\n");
	return (EXIT_FAILURE);
}

int			otool_macho(void *ptr)
{
	uint32_t	size_mh;

	s_b64(((struct mach_header*)ptr)->magic == MH_MAGIC_64);
	size_mh = s_b64(UN) ? sizeof(struct mach_header_64)
		: sizeof(struct mach_header);
	if (SIZE(ptr, ptr + size_mh + sizeof(struct load_command)))
		otool_macho_lc(ptr, (struct load_command*)(ptr + size_mh));
	else
	{
		ft_printf("truncated or malformed object (mach_header)\n");
		return (EXIT_FAILURE);
	}
	return (0);
}


