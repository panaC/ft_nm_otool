/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:00:30 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/28 10:20:25 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_tools.h"

void			param_attr(t_format *t)
{
	if (t->attr_0 && t->attr_moins)
		t->attr_0 = FALSE;
	if (t->attr_0 && t->precision >= 0)
		t->attr_0 = FALSE;
	if (t->attr_plus && t->attr_space)
		t->attr_space = FALSE;
	if ((t->op == 'u' || t->op == 'U') && t->attr_dieze)
		t->attr_dieze = FALSE;
	if (CONV_OUX && t->attr_space)
		t->attr_space = FALSE;
	if (CONV_OUX && t->attr_plus)
		t->attr_plus = FALSE;
}

char			*param_precision(int precision, char *s)
{
	char	*str_zero;
	int		sum;

	if (precision > 0)
	{
		sum = precision - (int)ft_strlen(s);
		if (sum < 0)
			sum = 0;
		str_zero = ft_strnew((size_t)precision);
		str_zero = (char *)ft_memset(str_zero, '0', (size_t)sum);
		str_zero = ft_strcat(str_zero, s);
		return (str_zero);
	}
	return (ft_strdup(s));
}

int				unicode(char **ret, wint_t c, t_bool op)
{
	int			i;

	i = -1;
	(*ret) = ft_strnew(4);
	if (op && (c <= 0x7F || op))
		(*ret)[++i] = c;
	else if (c <= 0x7FF)
	{
		(*ret)[++i] = (c >> 6) + 0xC0;
		(*ret)[++i] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF && (c < 0xD800 || c > 0xDFFF))
	{
		(*ret)[++i] = (c >> 12) + 0xE0;
		(*ret)[++i] = ((c >> 6) & 0x3F) + 0x80;
		(*ret)[++i] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF && (c < 0xD800 || c > 0xDFFF))
	{
		(*ret)[++i] = (c >> 18) + 0xF0;
		(*ret)[++i] = ((c >> 12) & 0x3F) + 0x80;
		(*ret)[++i] = ((c >> 6) & 0x3F) + 0x80;
		(*ret)[++i] = (c & 0x3F) + 0x80;
	}
	return ((i < 0) ? i : i + 1);
}
