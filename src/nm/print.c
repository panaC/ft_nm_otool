#include <mach-o/nlist.h>

void            nm_print_64(struct nlist_64 *list, uint32_t *sorted_array, uint32_t nb_symb, uint32_t stroff)
{
    while (nb_symb)
    {
        ft_printf("%0.8x%0.8x %s\n",
                  list[sorted_array[nb_symb]].n_value >> 32,
                  list[sorted_array[nb_symb]].n_value,
                  stroff + list[sorted_array[nb_symb]].n_un.n_strx);
        --nb_symb;
    }
}

void            nm_print_32(struct nlist *list, uint32_t *sorted_array, uint32_t nb_symb, uint32_t stroff)
{
    while (nb_symb)
    {
        ft_printf("%0.8x %s\n",
                  list[sorted_array[nb_symb]].n_value,
                  stroff + list[sorted_array[nb_symb]].n_un.n_strx);
        --nb_symb;
    }
}