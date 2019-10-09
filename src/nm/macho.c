/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:01:26 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/09 20:32:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "common.h"

void		print_section(struct segment_command_64* sc)
{
	uint32_t				i = 0;
	struct section_64	*sec;
	static int			num_sec = 0;

	ft_printf("%s:\n", sc->segname);
	sec = (struct section_64*)((void*)sc + sc->cmdsize);
	while (i < sc->nsects)
	{
		ft_printf("%d: %s - %s\n", ++num_sec, sec->sectname, sec->segname);
		++sec;
		++i;
	}
}

int			nm_macho(void *ptr)
{
	uint32_t	size_mh;

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

	nb_load_cmd = s_b64(UN) ?
		((struct mach_header_64*)ptr)->ncmds :
		((struct mach_header*)ptr)->ncmds;
	// ft_printf("nb of load cmd %d\n", nb_load_cmd);
	while (nb_load_cmd--)
	{
		if (SIZE(ptr, (void*)lc + lc->cmdsize))
		{
			// dont forget return 
			if (lc->cmd == LC_SYMTAB)
				nm_macho_symtab(ptr, (struct symtab_command*)lc);
			if (lc->cmd == LC_SEGMENT_64)
				print_section((struct segment_command_64*)lc);
			lc = (struct load_command*)((void*)lc + lc->cmdsize);
		}
		else
		{
			ft_printf("truncated or malformed object (load_command)\n");
			return (EXIT_FAILURE);
		}
	}
	ft_printf("truncated or malformed object (symtab_command)\n");
	return (EXIT_FAILURE);
}

int			nm_macho_symtab(void *ptr, struct symtab_command *symtab)
{
	uint32_t	*sorted_array;
	int			ret;

	// ft_printf("nb symbole table %d\n", symtab->nsyms);
	ret = EXIT_FAILURE;
	if ((sorted_array = malloc(sizeof(uint32_t) * symtab->nsyms)) == NULL)
		return (ret);
	if (SIZE(ptr, ptr + symtab->stroff + symtab->strsize))
	{
		sort_array(sorted_array,
				ptr + symtab->stroff,
				(struct nlist_64 *)(ptr + symtab->symoff),
				symtab->nsyms);
		ret = nm_print(ptr, sorted_array, symtab);
		free(sorted_array);
	}
	else
		ft_printf("truncated or malformed object (string_table)\n");
	return (ret);
}
