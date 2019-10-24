/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:01:26 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/24 22:26:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "common.h"

void		sectname(t_segcmd *sc, int rz)
{
	t_sect				*sect;
	static uint32_t		num_sec = 1;
	uint32_t			i;

	if (rz == 1)
	{
		return ((void)((num_sec = 0)));
	}
	sect = (t_sect*)((void*)sc + GES(sc));
	i = 0;
	while (i < GET(sc, nsects))
	{
		/*
		if (ft_strncmp(GET(sect, sectname), SECT_TEXT, 16) == 0||
				ft_strncmp(GET(sect, sectname), SECT_DATA, 16) == 0 ||
				ft_strncmp(GET(sect, sectname), SECT_BSS, 16) == 0 ||
				ft_strncmp(GET(sect, sectname), SECT_COMMON, 16) == 0)
			s_array(GET(sect, sectname), num_sec, 1);
		else
			s_array(GET(sect, segname), num_sec, 1);
			*/
		s_array(GET(sect, sectname), num_sec, 1);
		//ft_printf("%d %s %s %s\n", num_sec, GET(sect, segname), GET(sect, sectname), s_array(NULL, num_sec, 0));
		sect = (void*)sect + GES(sect);
		++num_sec;
		++i;
	}
}

int			nm_macho(void *ptr)
{
	uint32_t	size_mh;

	s_b64(((struct mach_header*)ptr)->magic == MH_MAGIC_64);
	size_mh = s_b64(UN) ? sizeof(struct mach_header_64)
		: sizeof(struct mach_header);
	if (SIZE(ptr, ptr + size_mh + sizeof(struct load_command)))
		nm_macho_lc(ptr, (struct load_command*)(ptr + size_mh));
	else
	{
		ft_printf("truncated or malformed object (mach_header)\n");
		return (EXIT_FAILURE);
	}
	return (0);
}

int			nm_macho_lc(void *ptr, struct load_command *lc)
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
			if (lc->cmd == LC_SYMTAB)
				ret = nm_macho_symtab(ptr, (struct symtab_command*)lc);
			if (lc->cmd == LC_SEGMENT_64 || lc->cmd == LC_SEGMENT)
				sectname((t_segcmd*)lc, 0);
			lc = (struct load_command*)((void*)lc + lc->cmdsize);
		}
		else
			break ;
	}
	if (ret)
		ft_printf("truncated or malformed object (symtab_command)\n");
	sectname(NULL, 1);
	return (ret);
}

int			nm_macho_symtab(void *ptr, struct symtab_command *symtab)
{
	char		**string_array;
	uint32_t	*sorted_array;
	int			ret;

	ret = EXIT_FAILURE;
	if ((sorted_array = (uint32_t*)malloc(sizeof(uint32_t) * symtab->nsyms))
			== NULL)
		return (ret);
	if ((string_array = (char **)ft_memalloc(sizeof(char*) * symtab->nsyms))
			== NULL)
		return (ret);
	if (SIZE(ptr, ptr + symtab->stroff + symtab->strsize) &&
		SIZE(ptr, ptr + symtab->symoff + SLI() * symtab->nsyms))
	{
		nm_print_buffer(ptr, string_array, symtab);
		sort_array(ptr, sorted_array, symtab);
		nm_print(ptr, string_array, sorted_array, symtab);
		ret = 0;
	}
	else
		ft_printf("truncated or malformed object (string_table)\n");
	free(sorted_array);
	return (ret);
}
