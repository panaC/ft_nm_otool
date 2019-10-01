/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uox_attr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:31:31 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 20:59:19 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "format_uox.h"
#include "format_tools.h"
#include <stdio.h>

static char				*static_param_x(t_format *t, char *s, char *tmp)
{
	if (t->attr_dieze && !t->attr_0)
	{
		s = ft_strjoin(((t->op == 'x') ? "0x" : "0X"), tmp);
		tmp = fill_length_param(s, ((t->attr_0) ? '0' : ' '), t->attr_moins,
				((t->attr_dieze && t->attr_0) ? t->length_field - 2 :
				t->length_field));
		ft_strdel(&s);
	}
	else
		tmp = fill_length_param(s, ((t->attr_0) ? '0' : ' '), t->attr_moins,
				((t->attr_dieze && t->attr_0) ? t->length_field - 2 :
				t->length_field));
	if (t->attr_dieze && t->attr_0)
	{
		s = ft_strjoin(((t->op == 'x') ? "0x" : "0X"), tmp);
		ft_strdel(&tmp);
	}
	else
		s = tmp;
	return (s);
}

static char				*static_param_o(t_format *t, char *s, char *tmp)
{
	if (t->attr_dieze && !t->attr_0 && s[0] != '0')
	{
		s = ft_strjoin("0", tmp);
		tmp = fill_length_param(s, ((t->attr_0) ? '0' : ' '), t->attr_moins,
				((t->attr_dieze && s[0] != '0') ?
				t->length_field - 1 : t->length_field));
		ft_strdel(&s);
	}
	else
		tmp = fill_length_param(s, ((t->attr_0) ? '0' : ' '), t->attr_moins,
				((t->attr_dieze && s[0] != '0') ?
				t->length_field - 1 : t->length_field));
	if (t->attr_dieze && t->attr_0)
	{
		s = ft_strjoin(((s[0] == '0') ? "" : "0"), tmp);
		ft_strdel(&tmp);
	}
	else
		s = tmp;
	return (s);
}

char					*param_attribut_uox(t_format *t, char *s)
{
	char				*tmp;

	param_attr(t);
	tmp = s;
	if (t->op == 'x' || t->op == 'X')
		s = static_param_x(t, s, tmp);
	else if (t->op == 'o' || t->op == 'O')
		s = static_param_o(t, s, tmp);
	else
		s = fill_length_param(tmp, ((t->attr_0) ? '0' : ' '),
				t->attr_moins, t->length_field);
	return (s);
}
