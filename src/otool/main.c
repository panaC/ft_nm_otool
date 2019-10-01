#include <ft_printf.h>

int         main(int argc, char **argv)
{
    if (argc > 1) {
        ft_printf("%s\n", argv[1]);
    }
    return (0);
}