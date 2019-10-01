/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:45:23 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 20:57:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "format_d.h"
#include "format_tools.h"

long long int		cast_format_d(t_format *t)
{
	if (t->length_type == code_hh)
		return ((long long int)(char)va_arg(t->arg, int));
	if (t->length_type == code_h)
		return ((long long int)(short)va_arg(t->arg, int));
	if (t->length_type == code_ll)
		return (va_arg(t->arg, long long int));
	if (t->length_type == code_l)
		return ((long long int)va_arg(t->arg, long int));
	if (t->length_type == code_j)
		return ((long long int)va_arg(t->arg, intmax_t));
	if (t->length_type == code_z)
		return ((long long int)va_arg(t->arg, size_t));
	return ((long long int)va_arg(t->arg, int));
}

char				*param_precision_d(int precision,
		long long int value, char *s)
{
	if (value == 0 && precision == 0)
		return (ft_strdup(""));
	if (precision <= (int)ft_strlen(s))
		return (ft_strdup(s));
	return (param_precision(precision, s));
}

char				*param_attribut_d(t_format *t, long long int value,
		char *s)
{
	char		*tmp;

	param_attr(t);
	tmp = s;
	if (t->attr_0 && ((t->attr_space + t->attr_plus) || value < 0))
	{
		if (value < 0)
			s = ft_strjoin("-", fill_length_param(tmp,
						'0', t->attr_moins, t->length_field - 1));
		else
			s = ft_strjoin((t->attr_plus ? "+" : " "), fill_length_param(tmp,
						'0', t->attr_moins, t->length_field - 1));
		return (s);
	}
	if (value < 0)
		tmp = ft_strjoin("-", s);
	else if (t->attr_plus || t->attr_space)
		tmp = ft_strjoin(((t->attr_plus) ? "+" : " "), s);
	else
		tmp = ft_strdup(s);
	s = fill_length_param(tmp,
			(t->attr_0 ? '0' : ' '), t->attr_moins, t->length_field);
	ft_strdel(&tmp);
	return (s);
}

char				*conv_format_d(t_format *t)
{
	char			*ret;
	char			*tmp;
	long long int	value;

	if (t->op == 'D')
		t->length_type = code_l;
	value = cast_format_d(t);
	ret = ft_itoa_long(value);
	tmp = param_precision_d(t->precision, value, ret);
	ft_strdel(&ret);
	ret = param_attribut_d(t, value, tmp);
	ft_strdel(&tmp);
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}
