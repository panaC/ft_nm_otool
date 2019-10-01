/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:37:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 21:03:00 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

char		*fill_length_param(char *s, char car, t_bool is_left, size_t size)
{
	char	*ret;
	char	*tmp;
	size_t	sz;

	if ((int)size < 0)
		size = 0;
	if (s == NULL)
		return (ft_strdup(""));
	sz = size - ft_strlen(s);
	if ((int)(sz) <= 0)
		return (ft_strdup(s));
	tmp = ft_strnew(sz);
	tmp = (char*)ft_memset(tmp, car, sz);
	if (is_left)
		ret = ft_strjoin(s, tmp);
	else
		ret = ft_strjoin(tmp, s);
	ft_memdel((void**)&tmp);
	return (ret);
}
