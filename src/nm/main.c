/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:04:10 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/06 22:04:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "common.h"

int			main(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		if (argc > 2)
			ft_printf("\n%s:\n", argv[i]);
		if (open_file(argv[i], &nm_magic))
			ret = EXIT_FAILLURE;
		i++;
	}
	return (0);
}
