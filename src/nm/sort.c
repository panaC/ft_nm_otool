#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>
#include <mach-o/nlist.h>

static void     swap(uint32_t *a, uint32_t *b)
{
    uint32_t         tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

static uint32_t         *init_sort_array(uint32_t *array, uint32_t n)
{
    uint32_t    i;

    i = 0;
    while (i < n)
    {
        array[i] = i;
        ++i;
    }
    return (array);
}

void            sort_array(uint32_t *array, void *off, struct nlist_64 *l, uint32_t n)
{
    int         flag;
    uint32_t    i;

    init_sort_array(array, n);
    flag = 1;
    while (flag)
    {
        flag = 0;
        i = 0;
        while (i < n - 1)
        {
            if (ft_strcmp(off + l[array[i]].n_un.n_strx, off + l[array[i + 1]].n_un.n_strx) > 0)
            {
                swap(array + i, array + i + 1);
                flag = 1;
            }
            ++i;
        }
    }
}