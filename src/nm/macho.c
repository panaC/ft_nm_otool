#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <ft_printf.h>
#include "common.h"

void        nm_macho(void *ptr, int b_swap, int b_64bit)
{
    // think to add a swapp fucntion on load command , ...
    uint32_t    nb_load_cmd;
    void        *p;

    nb_load_cmd = b_64bit ? ((struct mach_header_64*)ptr)->ncmds : ((struct mach_header_64*)ptr)->ncmds;
    // ft_printf("nb of load cmd %d\n", nb_load_cmd);
    p = ptr;
    p += b_64bit ? sizeof(struct mach_header_64) : sizeof(struct mach_header);
    while (nb_load_cmd)
    {
        if (((struct load_command*)p)->cmd == LC_SYMTAB)
        {
            nm_macho_symtab(ptr, (struct symtab_command*)p, b_swap, b_64bit);
        }
        p += ((struct load_command*)p)->cmdsize;
        --nb_load_cmd;
    }
}

void        nm_macho_symtab(void *ptr, struct symtab_command *symtab, int b_swap, int b_64bit)
{
	uint32_t 		    *sorted_array;

    // ft_printf("nb symbole table %d\n", symtab->nsyms);
    sorted_array = malloc(sizeof(uint32_t) * symtab->nsyms);
    sort_array(sorted_array,
               ptr + symtab->stroff,
               (struct nlist_64 *)(ptr + symtab->symoff),
               symtab->nsyms);
    if (b_swap)
    {
        // Swap n_list
    }
    if (b_64bit)
    {
        // 64b n_list
    }
    nm_print((t_nlist_p)(struct nlist*)(ptr + symtab->symoff),
             sorted_array,
             symtab->nsyms,
             ptr + symtab->stroff);
    free(sorted_array);
}