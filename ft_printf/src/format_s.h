/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:05:34 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/31 11:41:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_S_H
# define FORMAT_S_H
# include "../inc/ft_printf.h"
# include <wchar.h>

char				*conv_format_s(t_format *t);
char				*param_attribut_s(t_format *t, char *s);
char				*param_precision_s(t_format *t, wint_t *s);
wint_t				*cast_format_s(t_format *t);

#endif
