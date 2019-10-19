/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:10 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 17:04:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "common.h"

int			main(int argc, char **argv)
{
	int		i;
	int		start;
	int		ret;

	i = 1;
	ret = 0;
	while (argc > i && argv[i][0] == '-')
	{
		if (check_arg(argv[i++] + 1))
			return (ret);
	}
	start = i;
	while (i < argc)
	{
		if (argc - start > 1)
			ft_printf("\n%s:\n", argv[i]);
		if (open_file(argv[i], &nm_magic))
			ret = EXIT_FAILLURE;
		i++;
	}
	return (ret);
}
