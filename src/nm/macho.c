/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:01:26 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/16 16:08:30 by pleroux          ###   ########.fr       */
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
	// ft_printf("%s:\n", GET(sc, segname));
	sect = (t_sect*)((void*)sc + GET(sc, cmdsize));
	i = 0;
	while (i < GET(sc, nsects))
	{
		if (GET(sect, sectname)[0] && GET(sect, sectname)[0] != 25)
			s_array(GET(sect, sectname), num_sec, 1);
		else
			s_array(GET(sc, segname), num_sec, 1);
		// ft_printf("%d: %s - %s\n", num_sec, GET(sect, sectname), GET(sect, segname));
		sect = (void*)sect + sizeof(t_sect); //FIX
		sect = (void*)sect + GES(sect);
		++num_sec;
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
				sectname((t_segcmd*)lc, 0);
			lc = (struct load_command*)((void*)lc + lc->cmdsize);
		}
		else
		{
			ft_printf("truncated or malformed object (load_command)\n");
			return (EXIT_FAILURE);
		}
	}
	//ft_printf("truncated or malformed object (symtab_command)\n");
	sectname(NULL, 1); //reset
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
				(t_nlist_p)(struct nlist*)(ptr + symtab->symoff),
				symtab->nsyms);
		ret = nm_print(ptr, sorted_array, symtab);
		free(sorted_array);
	}
	else
		ft_printf("truncated or malformed object (string_table)\n");
	return (ret);
}
