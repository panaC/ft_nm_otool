#include <ft_printf.h>
#include "common.h"

int         main(int argc, char **argv)
{
    int     i;
    int     ret;

    i = 1;
    ret = 0;
    while (i < argc)
    {
        if (open_file(argv[i], &nm_magic))
            ret = EXIT_FAILLURE;
        i++;
    }
    return (0);
}
