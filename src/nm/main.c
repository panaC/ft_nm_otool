#include <ft_printf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

void        macho_64_symtab(void *ptr, struct symtab_command *symtab)
{
    uint32_t    nb_sym_tab;
    void        *p;

    nb_sym_tab = symtab->nsyms;
    ft_printf("nb symbole table %d\n", nb_sym_tab);
    p = ptr;
    p += symtab->symoff;
    while (nb_sym_tab)
    {
        ft_printf("%0.8x%0.8x %s\n", ((struct nlist_64*)p)->n_value >> 32, ((struct nlist_64*)p)->n_value,
            ptr + symtab->stroff + ((struct nlist_64*)p)->n_un.n_strx);
        p += sizeof(struct nlist_64);
        --nb_sym_tab;
    }
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
}

int         main(int argc, char **argv)
{
    int         fd;
    void        *ptr;
    struct stat buf;

    if (argc < 2)
    {
        ft_printf("a mach-o file is needed\n");
        return (1);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        ft_printf("can't open %s\n", argv[1]);
        return (1);
    }
    if (fstat(fd, &buf) < 0)
    {
        ft_printf("can't get info on %s\n", argv[1]);
        return (1);
    }
    if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
        ft_printf("can't read %s\n", argv[1]);
        return (1);
    }
    nm(ptr);
    if (munmap(ptr, buf.st_size) < 0)
    {
        ft_printf("can't desalocate memory mapping of %s\n", argv[1]);
        return (1);
    }
    return (0);
}