/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mae_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:02:51 by pierre            #+#    #+#             */
/*   Updated: 2018/05/04 21:02:25 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

char		*mae_attr(char *s, t_format *t)
{
	while (42)
	{
		if (!s || *s == '\0')
			return (s);
		if (*s == '#')
			t->attr_dieze = TRUE;
		else if (*s == '0')
			t->attr_0 = TRUE;
		else if (*s == ' ')
			t->attr_space = TRUE;
		else if (*s == '-')
			t->attr_moins = TRUE;
		else if (*s == '+')
			t->attr_plus = TRUE;
		else
			return (s);
		s++;
	}
	return (s);
}

char		*mae_length(char *s, t_format *t)
{
	if (s && *s && ft_isnum(*s))
		t->length_field = ft_atoi(s);
	return (s + ((t->length_field > -1) ? ft_len(t->length_field) : 0));
}

char		*mae_precision(char *s, t_format *t)
{
	if (s && *s && *s == '.')
	{
		s++;
		t->precision = ft_atoi(s);
		if (t->precision < 0)
		{
			t->precision = -1;
			s++;
		}
		while (*s && ft_isnum(*s))
			s++;
	}
	return (s);
}

char		*mae_cast(char *s, t_format *t)
{
	char p;

	p = 0;
	while (42)
	{
		if (!s || *s == '\0')
			return (s);
		if (*s == 'h' && p == 'h')
			t->length_type = code_hh;
		else if (*s == 'h')
			t->length_type = code_h;
		else if (*s == 'l' && p == 'l')
			t->length_type = code_ll;
		else if (*s == 'l')
			t->length_type = code_l;
		else if (*s == 'j')
			t->length_type = code_j;
		else if (*s == 'z')
			t->length_type = code_z;
		else
			return (s);
		p = *s;
		s++;
	}
	return (s);
}

char		*mae_parse(char *s, t_format *t)
{
	return (mae_cast(mae_precision(mae_length(mae_attr(s, t), t), t), t));
}
