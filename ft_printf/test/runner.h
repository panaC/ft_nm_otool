/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:07:22 by pierre            #+#    #+#             */
/*   Updated: 2018/01/29 15:02:17 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RUNNER_H_
# define __RUNNER_H_

#include <libft.h>
#include <stdio.h>
#include "../src/format_d.h"
#include "../inc/ft_printf.h"
#include "../src/mae_parse.h"
#include "../src/resolve_format.h"
#include "tddc.h"

extern int gi;

int all_tests();
int param_test();
int mae_parse_test();
int format_d_test();
int resolve_format_test();
int ft_vasprintf_test();

#endif
