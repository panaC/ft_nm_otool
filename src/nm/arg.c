/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:43:39 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/16 21:12:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>
#include "common.h"

int			print_arg(void)
{
	ft_putstr("USAGE: nm [options] <input files>\n\n");
	ft_putstr("OPTIONS:\n\n");
	ft_putstr(" -a : Display all symbol table entries, \
			including those inserted for use by debuggers.\n");
	ft_putstr(" -p : Don't sort; display in symbol-table order.\n");
	ft_putstr(" -r : Sort in reverse order.\n");
	ft_putstr(" -h : this help\n");
	return (1);
}

int			check_arg(char *arg)
{
	char	c;

	while ((c = *(arg++)))
	{
		if (c == 'a')
			s_a_disp(true);
		else if (c == 'p')
			s_a_not_sort(true);
		else if (c == 'r')
			s_a_sort(true);
		else
			return (print_arg());
	}
	return (0);
}
