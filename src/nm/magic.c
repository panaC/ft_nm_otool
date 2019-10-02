#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <ar.h>

int         nm_magic(void *ptr)
{
    if (*(unsigned int*)ptr == MH_MAGIC_64)
        macho_64(ptr);
    if (*(unsigned int*)ptr == MH_CIGAM_64)
        ft_printf("macho-64 inv");
    if (*(unsigned int*)ptr == MH_MAGIC)
        ft_printf("macho-32");
    if (*(unsigned int*)ptr == MH_CIGAM)
        ft_printf("macho-32 inv");
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
    return (0);
}