/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:37:01 by pierre            #+#    #+#             */
/*   Updated: 2018/05/04 21:01:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <libft.h>
#include "../inc/ft_printf.h"

int				ft_printf(const char *s, ...)
{
	char		*str;
	va_list		ap;
	static int	size = 0;
	int			sl;

	va_start(ap, s);
	sl = ft_vasprintf(&str, s, ap);
	va_end(ap);
	if (sl > 0)
	{
		write(1, str, sl);
		ft_strdel(&str);
	}
	if (size >= 0)
		size = sl;
	return (size);
}
