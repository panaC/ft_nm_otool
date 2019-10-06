#include <mach-o/nlist.h>
#include <ft_printf.h>
#include "common.h"

char            type_char(void *list)
{
    // ft_printf("%0.2x - %0.2x\n", (list->n_type & N_TYPE), (list->n_sect));
    if ((GET_NL(list)->n_type & N_TYPE) == N_UNDF)
        return 'U';
    if ((GET_NL(list)->n_type & N_TYPE) == N_ABS)
        return 'A';
    if ((GET_NL(list)->n_type & N_TYPE) == N_PBUD)
        return 'S';
    if ((GET_NL(list)->n_type & N_TYPE) == N_INDR)
        return 'I';
    if ((GET_NL(list)->n_type & N_TYPE) == N_SECT)
    {
        return 'p';
    }
    return 'S';
}

void            nm_print_64(struct nlist_64 *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff)
{
    uint32_t         i;

    i = 0;
    while (i < nb_symb)
    {
        if (list[sorted_array[i]].n_value)
            ft_printf("%0.8x%0.8x %c %s\n",
                      list[sorted_array[i]].n_value >> 32,
                      list[sorted_array[i]].n_value,
                      type_char_64(list + sorted_array[i]),
                      stroff + list[sorted_array[i]].n_un.n_strx);
        else
            ft_printf("%16c %c %s\n",
                      ' ',
                      type_char_64(list + sorted_array[i]),
                      stroff + list[sorted_array[i]].n_un.n_strx);
        ++i;
    }
}

void            nm_print_32(struct nlist *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff)
{
    uint32_t         i;

    i = 0;
    while (i < nb_symb)
    {
        ft_printf("%0.8x %c %s\n",
                  list[sorted_array[i]].n_value,
                  type_char_32(list + sorted_array[i]),
                  stroff + list[sorted_array[i]].n_un.n_strx);
        ++i;
    }
}