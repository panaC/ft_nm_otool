/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mae_parse.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:21:12 by pierre            #+#    #+#             */
/*   Updated: 2018/01/29 15:34:01 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int ma_01()
{
	t_format *t = init_struct();
	mae_attr("#d", t);
	RC(t->attr_dieze, 1);
	return (0);
}

static int ma_02()
{
	t_format *t = init_struct();
	mae_attr("-d", t);
	RC(t->attr_moins, 1);
	return (0);
}

static int ma_03()
{
	t_format *t = init_struct();
	mae_attr("+d", t);
	RC(t->attr_plus, 1);
	return (0);
}

static int ma_04()
{
	t_format *t = init_struct();
	mae_attr(" d", t);
	RC(t->attr_space, 1);
	return (0);
}

static int ma_05()
{
	t_format *t = init_struct();
	mae_attr("0d", t);
	RC(t->attr_0, 1);
	return (0);
}

static int ma_06()
{
	t_format *t = init_struct();
	mae_attr("d", t);
	RC(t->attr_dieze, 0);
	RC(t->attr_0, 0);
	RC(t->attr_space, 0);
	RC(t->attr_plus, 0);
	RC(t->attr_moins, 0);
	RC(t->attr_dieze, 0);
	return (0);
}

static int ma_07()
{
	t_format *t = init_struct();
	mae_attr("123d", t);
	RC(t->attr_dieze, 0);
	RC(t->attr_0, 0);
	RC(t->attr_space, 0);
	RC(t->attr_plus, 0);
	RC(t->attr_moins, 0);
	RC(t->attr_dieze, 0);
	return (0);
}

static int ma_08()
{
	t_format *t = init_struct();
	mae_attr("#0 +- +d", t);
	RC(t->attr_dieze, 1);
	RC(t->attr_0, 1);
	RC(t->attr_space, 1);
	RC(t->attr_plus, 1);
	RC(t->attr_moins, 1);
	RC(t->attr_dieze, 1);
	return (0);
}

static int		ma_test()
{
	PT;
	_verify(ma_01);
	_verify(ma_02);
	_verify(ma_03);
	_verify(ma_04);
	_verify(ma_05);
	_verify(ma_06);
	_verify(ma_07);
	_verify(ma_08);
	return (0);
}

static int		ml_01()
{
	t_format *t = init_struct();
	mae_length(mae_attr("#0 +- +10d", t), t);
	RC(t->length_field, 10);
	return (0);
}

static int		ml_02()
{
	t_format *t = init_struct();
	mae_length(mae_attr("#0 +- +200d", t), t);
	RC(t->length_field, 200);
	return (0);
}

static int		ml_03()
{
	t_format *t = init_struct();
	mae_length(mae_attr("#0 +- -200d", t), t);
	RC(t->length_field, 200);
	return (0);
}

static int		ml_04()
{
	t_format *t = init_struct();
	mae_length(mae_attr("#0 +- +      200d", t), t);
	RC(t->length_field, 200);
	return (0);
}

static int		ml_05()
{
	t_format *t = init_struct();
	mae_length(mae_attr("d", t), t);
	RC(t->length_field, -1);
	return (0);
}

static int		ml_test()
{
	PT;
	_verify(ml_01);
	_verify(ml_02);
	_verify(ml_03);
	_verify(ml_04);
	_verify(ml_05);
	return (0);
}

static int		mp_01()
{
	t_format *t = init_struct();
	mae_precision(mae_length(mae_attr("#0 +- +10.10d", t), t), t);
	RC(10, t->precision);
	return (0);
}

static int		mp_02()
{
	t_format *t = init_struct();
	mae_precision(mae_length(mae_attr("#0 +- +300.200d", t), t), t);
	RC(200, t->precision);
	return (0);
}

static int		mp_03()
{
	t_format *t = init_struct();
	mae_precision(mae_length(mae_attr("#0 +- -200.0d", t), t), t);
	RC(0, t->precision);
	return (0);
}

static int		mp_04()
{
	t_format *t = init_struct();
	mae_precision(mae_length(mae_attr("#0 +- +      200.-10d", t), t), t);
	RC(-1, t->precision);
	return (0);
}

static int		mp_test()
{
	PT;
	_verify(mp_01);
	_verify(mp_02);
	_verify(mp_03);
	_verify(mp_04);
	return (0);
}

static int		mc_01()
{
	t_format *t = init_struct();
	mae_cast(mae_precision(mae_length(mae_attr("#0 +- +      200.-10d", t), t), t), t);
	RC(code_none, t->length_type);
	return (0);
}

static int		mc_02()
{
	t_format *t = init_struct();
	mae_cast(mae_precision(mae_length(mae_attr("#0 +- +      200.-10lld", t), t), t), t);
	RC(code_ll, t->length_type);
	return (0);
}

static int		mc_03()
{
	t_format *t = init_struct();
	mae_cast(mae_precision(mae_length(mae_attr("#0 +- +      200.-10llllmd", t), t), t), t);
	RC(code_ll, t->length_type);
	return (0);
}

static int		mc_04()
{
	t_format *t = init_struct();
	mae_cast(mae_precision(mae_length(mae_attr("#0 +- +      200.-10hhd", t), t), t), t);
	RC(code_hh, t->length_type);
	return (0);
}

static int		mc_05()
{
	t_format *t = init_struct();
	mae_cast(mae_precision(mae_length(mae_attr("#0 +- +      200.-10hd", t), t), t), t);
	RC(code_h, t->length_type);
	return (0);
}

static int		mc_test()
{
	PT;
	_verify(mc_01);
	_verify(mc_02);
	_verify(mc_03);
	_verify(mc_04);
	_verify(mc_05);
	return (0);
}

int		mae_parse_test()
{
	return (ma_test() + ml_test() + mp_test() + mc_test());
}
