/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:07:21 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/06 22:30:31 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

# define EXIT_FAILLURE	1

# define GE(U)			((s_b64(UN)) ? (U->b64) : (U->b32))
# define GET(U, M)		((s_b64(UN)) ? (U->b64.M) : (U->b32.M))
# define GEI(U, I)		(t_n)(s_b64(UN) ? (t_v)(U.b64 + I) : (t_v)(U.b32 + I))
# define GETI(U, I, M)	((s_b64(UN)) ? (U.b64[I].M) : (U.b32[I].M))

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

typedef void*			t_v;
typedef t_nlist*		t_n;

/*
** common/
*/
int						open_file(char *path, void (*run)(void*));
int						free_file(int fd, void *ptr, size_t size, char *path);

int						s_swap(t_boo state);
int						s_b64(t_boo state);

/*
** nm/
*/
void					nm_magic(void *ptr);

void					nm_macho(void *ptr, int b_swap, int b_64bit);
void					nm_macho_symtab(void *ptr,
							struct symtab_command *symtab, int b_swap,
							int b_64bit);

void					nm_print(t_nlist_p list, uint32_t *sorted_array,
							uint32_t nb_symb, void *stroff);

void					sort_array(uint32_t *array, void *off,
							struct nlist_64 *l, uint32_t n);

#endif
