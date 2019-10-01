/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mae_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:18:51 by pierre            #+#    #+#             */
/*   Updated: 2018/01/29 15:58:52 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAE_PARSE_H
# define MAE_PARSE_H
# include "../inc/ft_printf.h"

char		*mae_attr(char *s, t_format *t);
char		*mae_length(char *s, t_format *t);
char		*mae_precision(char *s, t_format *t);
char		*mae_cast(char *s, t_format *t);
char		*mae_parse(char *s, t_format *t);

#endif
