/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:08:44 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/04 21:02:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include "../inc/ft_printf.h"

t_format		*init_struct(void)
{
	t_format	*ret;

	if (!(ret = (t_format*)ft_memalloc(sizeof(*ret))))
		return (NULL);
	ret->attr_dieze = FALSE;
	ret->attr_0 = FALSE;
	ret->attr_moins = FALSE;
	ret->attr_plus = FALSE;
	ret->attr_space = FALSE;
	ret->length_field = -1;
	ret->precision = -1;
	ret->length_type = code_none;
	ret->op = -1;
	ret->val_ret = 0;
	ret->flag_pc = FALSE;
	return (ret);
}
