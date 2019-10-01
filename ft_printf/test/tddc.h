/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tddc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:08:13 by pierre            #+#    #+#             */
/*   Updated: 2018/02/05 18:08:06 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __TDDC_H_
# define __TDDC_H_
# include <stdio.h>

extern int		tests_run;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

#define PT printf("TEST : %s -> %s\n", __FILE__, __func__)

#define RS(v1, v2) do { \
	printf("%s : attendu '%s' : obtenu '%s'\n", __func__, v1, v2); \
	_assert(ft_strcmp(v1, v2) == 0); \
	}while(0)
#define RC(v1, v2) do { \
	printf("%s : attendu '%d' : obtenu '%d'\n", __func__, v1, v2); \
	_assert(v1 == v2); \
	}while(0)
#define RU(v1, v2) do { \
	printf("%s : attendu '%S' : obtenu '%S'\n", __func__, v1, v2); \
	_assert(v1 == v2); \
	}while(0)
#define RM(v1, v2) do { \
	printf("%s : attendu '%S' : obtenu '%S'\n", __func__, v1, v2); \
	_assert(ft_memcmp(v1, v2, val_r) == 0); \
	}while(0)


#endif
