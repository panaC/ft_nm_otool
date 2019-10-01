/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:18:56 by pierre            #+#    #+#             */
/*   Updated: 2018/01/30 11:06:40 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORMAT_D_H
# define _FORMAT_D_H
# include "../inc/ft_printf.h"

long long int	cast_format_d(t_format *t);
char			*param_precision_d(int precision, long long int value, char *s);
char			*param_attribut_d(t_format *t, long long int value, char *s);
char			*conv_format_d(t_format *t);

#endif
