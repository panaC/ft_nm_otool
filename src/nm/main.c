#include <ft_printf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <ar.h>
#include "common.h"


void        macho_64_symtab(void *ptr, struct symtab_command *symtab)
{
    uint32_t			nb_sym_tab;
	uint32_t 		    *sorted_array;
	struct nlist_64		*list;

    nb_sym_tab = symtab->nsyms;
    ft_printf("nb symbole table %d\n", nb_sym_tab);

	list = (struct nlist_64*)(ptr + symtab->symoff);

	sorted_array = malloc(sizeof(uint32_t) * nb_sym_tab);
	uint32_t i = 0;
	while (i < nb_sym_tab)
	{
		sorted_array[i] = i;
		++i;
	}
    
    /*
	uint32_t min;
	i = 0;
	while (i < nb_sym_tab)
	{
		min = i;
		uint32_t j = 0;
		while (j < nb_sym_tab)
		{
			if (ft_strcmp(
                    ptr + symtab->stroff + list[min].n_un.n_strx,
                    ptr + symtab->stroff + list[j].n_un.n_strx) < 0)
			{
				min = j;
			}

			if (min != i)
			{
				int tmp = sorted_array[min];
				sorted_array[min] = sorted_array[i];
				sorted_array[i] = tmp;
			}
			++j;
		}
		++i;
	}
    */

    while (nb_sym_tab)
    {
        ft_printf("%0.8x%0.8x %s\n",
				list[sorted_array[nb_sym_tab]].n_value >> 32,
				list[sorted_array[nb_sym_tab]].n_value,
            	ptr + symtab->stroff + list[sorted_array[nb_sym_tab]].n_un.n_strx);
        --nb_sym_tab;
    }
	free(sorted_array);
}

void        macho_64(void *ptr)
{
    // header : nb cmd
    uint32_t    nb_load_cmd;
    void        *p;

    nb_load_cmd = ((struct mach_header_64*)ptr)->ncmds;
    ft_printf("nb of load cmd %d\n", nb_load_cmd);
    p = ptr;
    p += sizeof(struct mach_header_64);
    while (nb_load_cmd)
    {
        if (((struct load_command*)p)->cmd == LC_SYMTAB)
        {
            macho_64_symtab(ptr, (struct symtab_command*)p);
        }
        p += ((struct load_command*)p)->cmdsize;
        --nb_load_cmd;
    }
}

void        nm(void *ptr)
{
    // test magic number
    if (*(unsigned int*)ptr == MH_MAGIC_64)
        macho_64(ptr);
    
    if (*(unsigned int*)ptr == MH_CIGAM)
        ft_printf("macho-32 inv");

    if (*(unsigned int*)ptr == MH_CIGAM_64)
        ft_printf("macho-64 inv");
        //macho_64(ptr);
    
    if (*(unsigned int*)ptr == MH_MAGIC)
        ft_printf("macho-32");
    
    if (*(unsigned int*)ptr == FAT_MAGIC)
        ft_printf("fat-32");

    if (*(unsigned int*)ptr == FAT_MAGIC_64)
        ft_printf("fat-64");

    if (*(unsigned int*)ptr == FAT_CIGAM)
        ft_printf("fat-32 inv");

    if (*(unsigned int*)ptr == FAT_CIGAM_64)
        ft_printf("fat-64 inv");

    if (ft_strncmp((char*)ptr, ARMAG, SARMAG) == 0)
        ft_printf("arch");
}

int         main(int argc, char **argv)
{

    return (0);
}
