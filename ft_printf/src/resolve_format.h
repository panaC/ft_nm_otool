/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_format.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:09:22 by pleroux           #+#    #+#             */
/*   Updated: 2018/02/02 15:47:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_FORMAT_H
# define RESOLVE_FORMAT_H
# include "../inc/ft_printf.h"

t_bool		mae_format(char **ret, char *s, t_format *t);
void		resolve_format(char **ret, char *str, t_format *t);

#endif
