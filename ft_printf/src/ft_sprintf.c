/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:38:39 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 21:45:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <libft.h>
#include "../inc/ft_printf.h"

int				ft_sprintf(char **str, const char *s, ...)
{
	va_list		ap;
	int			sl;

	va_start(ap, s);
	sl = ft_vasprintf(str, s, ap);
	va_end(ap);
	return (sl);
}
