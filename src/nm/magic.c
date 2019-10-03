#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <ar.h>
#include "common.h"
#include <ft_printf.h>

static void         nm_magic_macho(void *ptr, char *path)
{

    ft_printf("\n%s:\n", path);
    if (*(unsigned int *)ptr == MH_MAGIC_64)
        nm_macho(ptr, 0, 1);
    if (*(unsigned int *)ptr == MH_CIGAM_64)
        nm_macho(ptr, 1, 1);
    if (*(unsigned int *)ptr == MH_MAGIC)
        nm_macho(ptr, 0, 0);
    if (*(unsigned int *)ptr == MH_CIGAM)
        nm_macho(ptr, 1, 0);
}

void                nm_magic(void *ptr, char *path)
{
    nm_magic_macho(ptr, path);
    if (*(unsigned int *)ptr == FAT_MAGIC)
        ft_printf("fat-32");
    if (*(unsigned int *)ptr == FAT_MAGIC_64)
        ft_printf("fat-64");
    if (*(unsigned int *)ptr == FAT_CIGAM)
        ft_printf("fat-32 inv");
    if (*(unsigned int *)ptr == FAT_CIGAM_64)
        ft_printf("fat-64 inv");
    if (ft_strncmp((char *)ptr, ARMAG, SARMAG) == 0)
        ft_printf("arch");
}