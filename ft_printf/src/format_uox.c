/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 09:09:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 20:58:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <stdint.h>
#include <stdio.h>
#include "format_uox.h"
#include "format_tools.h"

unsigned long long int	cast_format_uox(t_format *t)
{
	if (t->length_type == code_hh)
		return ((unsigned long long int)(unsigned char)va_arg(t->arg, int));
	if (t->length_type == code_h)
		return ((unsigned long long int)(unsigned short)va_arg(t->arg, int));
	if (t->length_type == code_ll)
		return (va_arg(t->arg, unsigned long long int));
	if (t->length_type == code_l)
		return ((unsigned long long int)va_arg(t->arg, unsigned long int));
	if (t->length_type == code_j)
		return ((unsigned long long int)va_arg(t->arg, uintmax_t));
	if (t->length_type == code_z)
		return ((unsigned long long int)va_arg(t->arg, size_t));
	return ((unsigned long long int)va_arg(t->arg, unsigned int));
}

char					*param_precision_uox(int precision,
		unsigned long long int value, char *s)
{
	if (value == 0 && precision == 0)
		return (ft_strdup(""));
	return (param_precision(precision, s));
}

char					*conv_format_uox(t_format *t)
{
	char					*ret;
	char					*tmp;
	unsigned long long int	value;

	if (t->op == 'O' || t->op == 'U')
		t->length_type = code_l;
	value = cast_format_uox(t);
	if (!t->flag_pc && value == 0 && (t->op == 'x' || t->op == 'X'))
		t->attr_dieze = FALSE;
	if (t->op == 'x' || t->op == 'X')
		ret = ft_itoa_base_long(value, ((t->op == 'x') ? BASE_SX : BASE_BX));
	else if (t->op == 'o' || t->op == 'O')
		ret = ft_itoa_base_long(value, BASE_O);
	else
		ret = ft_itoa_base_long(value, BASE_D);
	tmp = param_precision_uox(t->precision, value, ret);
	ft_strdel(&ret);
	ret = param_attribut_uox(t, tmp);
	ft_strdel(&tmp);
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}
