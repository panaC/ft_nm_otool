/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:46:35 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 16:07:44 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "common.h"

int			main(int argc, char **argv)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		ft_printf("%s:\n", argv[i]);
		if (open_file(argv[i], &otool_magic))
			ret = EXIT_FAILLURE;
		i++;
	}
	return (ret);
}
