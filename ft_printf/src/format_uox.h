/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uox.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:06:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/31 18:28:34 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_UOX_H
# define FORMAT_UOX_H
# include "../inc/ft_printf.h"
# define BASE_BX "0123456789ABCDEF"
# define BASE_SX "0123456789abcdef"
# define BASE_O  "01234567"
# define BASE_D  "0123456789"

char					*param_precision_uox(int precision,
		unsigned long long int value, char *s);
char					*param_attribut_uox(t_format *t, char *s);
unsigned long long int	cast_format_uox(t_format *t);
char					*conv_format_uox(t_format *t);

#endif
