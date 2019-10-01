/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:01:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 20:57:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include "../inc/ft_printf.h"
#include "../src/mae_parse.h"
#include "../src/resolve_format.h"
#include "../src/format_c.h"
#include "../src/format_tools.h"

wint_t				cast_format_c(t_format *t)
{
	if (t->length_type == code_l)
		return (va_arg(t->arg, wint_t));
	return ((wint_t)va_arg(t->arg, int));
}

char				*param_attribut_c(t_format *t, char *s)
{
	char			*tmp;

	tmp = s;
	if (t->op == 'c' && s[0] == 0)
	{
		tmp = fill_length_param(s, (t->attr_0 ? '0' : ' '), t->attr_moins,
				t->length_field - 1);
		if (t->attr_moins)
			s = ft_strnjoin(s, 1, tmp,
					((t->length_field < 0) ? 0 : t->length_field));
		else
			s = ft_strnjoin(tmp,
					((t->length_field < 0) ? 0 : t->length_field), s, 1);
		ft_strdel(&tmp);
		tmp = s;
	}
	else
	{
		t->length_field = (t->length_field / t->val_ret) * t->val_ret;
		tmp = fill_length_param(s, ' ', t->attr_moins, t->length_field);
	}
	return (tmp);
}

char				*conv_format_c(t_format *t)
{
	char			*ret;
	char			*tmp;
	wint_t			value;

	if (t->op == 'C')
		t->length_type = code_l;
	value = cast_format_c(t);
	if (t->length_type == code_l)
		t->op = 'C';
	t->val_ret = unicode(&tmp, value, (t->op == 'c') ? 1 : 0);
	ret = param_attribut_c(t, tmp);
	t->val_ret = ((t->length_field > 0) ? t->length_field : t->val_ret);
	ft_memdel((void**)&tmp);
	if (!ret)
		t->val_ret = -1;
	return (ret);
}
