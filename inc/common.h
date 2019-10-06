#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

typedef     enum
{
  undef = -1,
  false,
  true,
}           t_boo;

typedef     union 
{
  struct nlist    b32;
  struct nlist_64 b64;
}           t_nlist;


# define GET(un) s_b64(undef) ? un.b64 : un.b32
# define GET_NL(p) GET((t_nlist)p)

/*
** common/
*/
int         open_file(char *path, void (*run)(void*));
int         free_file(int fd, void *ptr, size_t size, char *path);

int         s_swap(t_boo state);
int         s_b64(t_boo state);

/*
** nm/
*/
void        nm_magic(void *ptr);

void        nm_macho(void *ptr, int b_swap, int b_64bit);
void        nm_macho_symtab(void *ptr, struct symtab_command *symtab, int b_swap, int b_64bit);

void        nm_print_64(struct nlist_64 *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff);
void        nm_print_32(struct nlist *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff);

void        sort_array(uint32_t *array, void *off, struct nlist_64 *l, uint32_t n);

# define EXIT_FAILLURE      1
#endif