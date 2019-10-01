/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:56:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/29 18:18:29 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include "../inc/ft_printf.h"
#include "../src/format_d.h"
#include "../src/mae_parse.h"
#include "../src/format_uox.h"
#include "../src/resolve_format.h"
#include "../src/format_c.h"
#include "../src/format_s.h"
#include "../src/format_tools.h"

char			*conv_format_p(t_format *t)
{
	t->attr_dieze = TRUE;
	t->length_type = code_l;
	t->op = 'x';
	t->flag_pc = TRUE;
	return (conv_format_uox(t));
}

char			*conv_format_pc(t_format *t)
{
	char			*ret;
	char			*tmp;

	tmp = ft_strdup("%");
	ret = fill_length_param(tmp, (t->attr_0 ? '0' : ' '), t->attr_moins,
			t->length_field);
	ft_strdel(&tmp);
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}

char			*conv_format_unknown(t_format *t, char *s)
{
	char		*ret;
	char		*tmp;

	tmp = ft_strnew(1);
	tmp[0] = t->op;
	ret = fill_length_param(tmp, (t->attr_0 && !t->attr_moins ? '0' : ' '),
			t->attr_moins, t->length_field);
	ft_strdel(&tmp);
	if (s && s[0] && s[1])
	{
		s = ft_strjoin(ret, s + 1);
		ft_strdel(&ret);
		ret = s;
	}
	if (!ret)
		t->val_ret = -1;
	else
		t->val_ret = ft_strlen(ret);
	return (ret);
}

t_bool			mae_format(char **ret, char *s, t_format *t)
{
	if (s || *s)
	{
		t->op = *s;
		if (*s == 'd' || *s == 'D' || *s == 'i')
			*ret = conv_format_d(t);
		else if (*s == 's' || *s == 'S' || *s == 'a')
			*ret = conv_format_s(t);
		else if (*s == 'p')
			*ret = conv_format_p(t);
		else if (*s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' ||
				*s == 'x' || *s == 'X')
			*ret = conv_format_uox(t);
		else if (*s == 'c' || *s == 'C')
			*ret = conv_format_c(t);
		else if (*s == '%')
			*ret = conv_format_pc(t);
		else
			*ret = conv_format_unknown(t, s);
		return (1);
	}
	*ret = NULL;
	t->val_ret = -1;
	return (0);
}

void			resolve_format(char **ret, char *str, t_format *t)
{
	char	*s;
	char	*tmp;

	s = str;
	*ret = NULL;
	while (str && *str && *str != '%')
		str++;
	if (str && *str == '%')
	{
		if (mae_format(&tmp, mae_parse(str + 1, t), t))
		{
			*str = '\0';
			*ret = ft_strnjoin(s, ft_strlen(s), tmp,
					((t->val_ret > 0) ? (size_t)t->val_ret : 0));
			ft_strdel(&tmp);
		}
		else
			*ret = ft_strdup("");
	}
	else if (str && *str == '\0')
		*ret = ft_strdup(s);
	t->val_ret += ft_strlen(s);
}
