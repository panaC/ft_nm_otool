/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:01:26 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/06 22:02:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "common.h"


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
			if (lc->cmd == LC_SYMTAB)
				nm_macho_symtab(ptr, (struct symtab_command*)lc);
			lc = (struct load_command*)((void*)lc + lc->cmdsize);
		}
		else
		{
			ft_printf("truncated or malformed object (load_command)\n");
			return (EXIT_FAILURE);
		}
	}
	return (0);
}

int			nm_macho_symtab(void *ptr, struct symtab_command *symtab)
{
	uint32_t	*sorted_array;
	int			ret;

	// ft_printf("nb symbole table %d\n", symtab->nsyms);
	if ((sorted_array = malloc(sizeof(uint32_t) * symtab->nsyms)) == NULL)
		return (EXIT_FAILURE);
	sort_array(sorted_array,
			ptr + symtab->stroff,
			(struct nlist_64 *)(ptr + symtab->symoff),
			symtab->nsyms);
	ret = nm_print((t_nlist_p)(struct nlist*)(ptr + symtab->symoff),
			sorted_array,
			symtab->nsyms,
			ptr + symtab->stroff);
	free(sorted_array);
	return (ret);
}
