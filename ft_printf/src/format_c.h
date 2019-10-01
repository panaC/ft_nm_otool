/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:35:24 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/30 16:44:17 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_C_H
# define FORMAT_C_H
# include <wchar.h>
# include "../inc/ft_printf.h"

wint_t				cast_format_c(t_format *t);;;;
char				*param_attribut_c(t_format *t, char *s);
char				*conv_format_c(t_format *t);

#endif
