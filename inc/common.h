#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

/*
** common/
*/
int         open_file(char *path, void (*run)(void*, char*));
int         free_file(int fd, void *ptr, size_t size, char *path);

/*
** nm/
*/
void        nm_magic(void *ptr, char *path);

void        nm_macho(void *ptr, int b_swap, int b_64bit);
void        nm_macho_symtab(void *ptr, struct symtab_command *symtab, int b_swap, int b_64bit);

void        nm_print_64(struct nlist_64 *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff);
void        nm_print_32(struct nlist *list, uint32_t *sorted_array, uint32_t nb_symb, void *stroff);

void        sort_array(uint32_t *array, void *off, struct nlist_64 *l, uint32_t n);

# define EXIT_FAILLURE      1
#endif