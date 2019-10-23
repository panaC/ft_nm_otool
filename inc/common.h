/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:07:21 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/23 23:39:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

# define EXIT_FAILLURE	1

# define ABS(A)			((A < 0) ? (A * -1) : A)
# define SIZE(A, B)		(ABS((int)(B - A)) <= s_size(UN))
# define GE(U)			((s_b64(UN)) ? (U->b64) : (U->b32))
# define GD(U)			((s_b64(UN)) ? (U.b64) : (U.b32))
# define GET(U, M)		((s_b64(UN)) ? (U->b64.M) : (U->b32.M))
# define GEI(C, U, I)	(C)(s_b64(UN) ? (t_v)(U.b64 + I) : (t_v)(U.b32 + I))
# define GETI(U, I, M)	((s_b64(UN)) ? (U.b64[I].M) : (U.b32[I].M))
# define GES(U)			(s_b64(UN) ? sizeof(U->b64) : sizeof(U->b32))
# define GED(U)			(s_b64(UN) ? sizeof(U.b64) : sizeof(U.b32))
# define SLI()			(s_b64(UN) ? sizeof(t_nli) : sizeof(struct nlist_64))

# define SORT(V)		(s_a_sort(UN) ? (V < 0) : (V > 0))

typedef enum			e_boo
{
	UN = -1,
	undef = -1,
	false,
	true,
}						t_boo;

typedef union			u_nlist
{
	struct nlist	b32;
	struct nlist_64	b64;
}						t_nlist;

typedef union			u_nlist_p
{
	struct nlist	*b32;
	struct nlist_64	*b64;
}						t_nlist_p;

typedef union			u_segcmd
{
	struct segment_command		b32;
	struct segment_command_64	b64;
}						t_segcmd;

typedef union			u_sect
{
	struct section		b32;
	struct section_64	b64;
}						t_sect;

typedef union			u_sect_p
{
	struct section		*b32;
	struct section_64	*b64;
}						t_sect_p;

typedef void*			t_v;
typedef t_nlist*		t_n;
typedef struct nlist	t_nli;

/*
** common/
*/
int						open_file(char *path, int (*run)(void*));

int						s_swap(t_boo state);
int						s_b64(t_boo state);
int						s_size(int size);
char					*s_array(char *data, uint8_t i, int mode);

int						s_a_disp(t_boo state);
int						s_a_sort(t_boo state);
int						s_a_not_sort(t_boo state);

uint16_t				swap_uint16(uint16_t val);
int16_t					swap_int16(int16_t val);
uint32_t				swap_uint32(uint32_t val);
int32_t					swap_int32(int32_t val);

/*
** nm/
*/
int						nm_magic(void *ptr);

int						nm_macho(void *ptr);
int						nm_macho_lc(void *ptr, struct load_command *lc);
int						nm_macho_symtab(void *ptr,
							struct symtab_command *symtab);

void					nm_print(char **string_array, uint32_t *sorted_array,
							struct symtab_command *symtab);
void					nm_print_buffer(void *ptr, char **string_array,
							struct symtab_command *symtab);

int						swap(uint32_t *a, uint32_t *b);
void					sort_array(void *ptr, uint32_t *array,
							struct symtab_command *symtab);

int						nm_fat(void*ptr);

int						check_arg(char *arg);


/*
** otool/
*/

int						otool_macho(void *ptr);
void					otool_print_memory(const void *addr, size_t size,
		uint64_t address);
int						otool_magic(void *ptr);
int						otool_fat(void *ptr);

#endif
