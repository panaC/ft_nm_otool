/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:07:21 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/16 16:05:16 by pleroux          ###   ########.fr       */
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
# define GET(U, M)		((s_b64(UN)) ? (U->b64.M) : (U->b32.M))
# define GEI(C, U, I)	(C)(s_b64(UN) ? (t_v)(U.b64 + I) : (t_v)(U.b32 + I))
# define GETI(U, I, M)	((s_b64(UN)) ? (U.b64[I].M) : (U.b32[I].M))
# define GES(U)			(s_b64(UN) ? sizeof(U->b64) : sizeof(U->b32))

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

typedef void*			t_v;
typedef t_nlist*		t_n;

/*
** common/
*/
int						open_file(char *path, int (*run)(void*));

int						s_swap(t_boo state);
int						s_b64(t_boo state);
int						s_size(int size);
char					*s_array(char *data, uint8_t i, int mode);

/*
** nm/
*/
int						nm_magic(void *ptr);

int						nm_macho(void *ptr);
int						nm_macho_lc(void *ptr, struct load_command *lc);
int						nm_macho_symtab(void *ptr,
							struct symtab_command *symtab);

int						nm_print(void *ptr, uint32_t *sorted_array,
							struct symtab_command *symtab);

void					sort_array(uint32_t *array, void *off,
							t_nlist_p l, uint32_t n);

#endif
