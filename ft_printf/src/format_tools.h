/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 08:59:30 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/02 09:20:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORMAT_TOOLS_H
# define _FORMAT_TOOLS_H
# include <wchar.h>
# include "../inc/ft_printf.h"
# define CONV_OUX (t->op == 'x' || t->op == 'X' || t->op == 'o' || t->op == 'u')

void			param_attr(t_format *t);
char			*param_precision(int precision, char *s);
int				unicode(char **ret, wint_t c, t_bool op);

#endif
