/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:56:04 by pierre            #+#    #+#             */
/*   Updated: 2018/05/04 21:01:55 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "../inc/ft_printf.h"
#include "../src/resolve_format.h"

static void	static_del(char **a, char **b, void **t)
{
	ft_strdel(a);
	ft_strdel(b);
	ft_memdel(t);
}

int			ft_vasprintf(char **ret, const char *s, va_list ap)
{
	va_list		bck;
	char		*str_recurs;
	char		*tmp;
	t_format	*t;
	int			tmp_size;

	if (((tmp_size = search_next_format(s))) == 0)
	{
		*ret = ft_strdup("");
		return (0);
	}
	t = init_struct();
	*ret = ft_strsub(s, 0, (size_t)tmp_size);
	va_copy(t->arg, ap);
	if (!(ft_strrchr(*ret, '%') == (*ret + ft_strlen(*ret) - 1)))
		va_arg(ap, void*);
	va_copy(bck, ap);
	tmp_size = ft_vasprintf(&str_recurs, s + tmp_size, bck);
	resolve_format(&tmp, *ret, t);
	ft_strdel(ret);
	*ret = ft_strnjoin(tmp, ((t->val_ret > 0) ? (size_t)t->val_ret : 0),
			str_recurs, ((tmp_size > 0) ? (size_t)tmp_size : 0));
	tmp_size += t->val_ret;
	static_del(&str_recurs, &tmp, (void**)&t);
	return (tmp_size);
}
