/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:36:18 by pierre            #+#    #+#             */
/*   Updated: 2018/01/27 23:40:33 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include "../inc/ft_printf.h"
#include "runner.h"
#include "tddc.h"

static int		flp_01()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 1, 1);
	RS(s, r);
	return (0);
}

static int		flp_02()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 1, 5);
	RS(s, r);
	return (0);
}

static int		flp_03()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 1, 7);
	RS("Hello  ", r);
	return (0);
}

static int		flp_04()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 0, 7);
	RS("  Hello", r);
	return (0);
}

static int		flp_05()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 0, 1);
	RS(s, r);
	return (0);
}

static int		flp_06()
{
	char *s = "Hello";
	char *r = fill_length_param(s, ' ', 0, 5);
	RS(s, r);
	return (0);
}

static int		flp_07()
{
	char *s = "Hello";
	char *r = fill_length_param(s, '0', 1, 7);
	RS("Hello00", r);
	return (0);
}

static int		flp_08()
{
	char *s = "Hello";
	char *r = fill_length_param(s, '0', 0, 7);
	RS("00Hello", r);
	return (0);
}

static int		flp_09()
{
	char *s = NULL;
	char *r = fill_length_param(s, '0', 0, 7);
	RS("", r);
	return (0);
}

int		param_test()
{
	PT;
	_verify(flp_01);
	_verify(flp_02);
	_verify(flp_03);
	_verify(flp_04);
	_verify(flp_05);
	_verify(flp_06);
	_verify(flp_07);
	_verify(flp_08);
	_verify(flp_09);
	return (0);
}

