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
    uint32_t			nb_sym_tab;
	char				*sorted_array;
	struct nlist_64		*list;

    nb_sym_tab = symtab->nsyms;
    ft_printf("nb symbole table %d\n", nb_sym_tab);

	list = (strut nlist_64*)(ptr + symtab->symoff);

	sorted_array = malloc(nb_sym_tab);
	int i = nb_sym_tab;
	while (i)
	{
		sorted_array[i] = nb_sym_tab - i;
		--i;
	}
	int min;
	i = nb_sym_tab;
	while (i)
	{
		min = i;
		int j = nb_sym_tab;
		while (j)
		{
			if (ft_strcmp(list[min].n_un.n_strx, list[j].n_un.n_strx) > 0)
			{
				min = j
			}

			if (min != i)
			{
				int tmp = sorted_array[min];
				sorted_array[min] = sorted_array[i];
				sorted_array[i] = tmp;
			}
			--j;
		}
		--i;
	}

    while (nb_sym_tab)
    {
        ft_printf("%0.8x%0.8x %s\n",
				list[sorted_array[nb_sym_tab]].n_value >> 32,
				list[sorted_array[nb_sym_tab]].n_value,
            	(void*)list + list[nb_sym_tab].n_un.n_strx);
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
