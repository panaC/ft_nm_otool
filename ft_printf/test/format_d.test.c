/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:58:07 by pierre            #+#    #+#             */
/*   Updated: 2018/01/29 09:39:10 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int ppd_01()
{
	char *s = "520";
	char *r;
	r = param_precision_d(-1, -520, s);
	RS(s,r);
	return (0);
}

static int ppd_02()
{
	char *s = "0";
	char *r;
	r = param_precision_d(0, 0, s);
	RS("",r);
	return (0);
}

static int ppd_03()
{
	char *s = "520";
	char *r;
	r = param_precision_d(1, -520, s);
	RS(s,r);
	return (0);
}

static int ppd_04()
{
	char *s = "520";
	char *r;
	r = param_precision_d(10, -520, s);
	RS("0000000520",r);
	return (0);
}

static int ppd_test()
{
	PT;
	_verify(ppd_01);
	_verify(ppd_02);
	_verify(ppd_03);
	_verify(ppd_04);
	return (0);
}

static int pad_01()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 0;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 0;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520", r);
	return (0);
}

static int pad_02()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 0;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 0;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS(s, r);
	return (0);
}

static int pad_03()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = 10;
	t->attr_0 = 0;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 0;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-0000000520", r);
	return (0);
}

static int pad_04()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 0;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS(s, r);
	return (0);
}

static int pad_05()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-000000520", r);
	return (0);
}

static int pad_06()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("0000000520", r);
	return (0);
}

static int pad_07()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-000000520", r);
	return (0);
}

static int pad_08()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("+000000520", r);
	return (0);
}

static int pad_09()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520", r);
	return (0);
}

static int pad_10()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("+520", r);
	return (0);
}

static int pad_11()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520      ", r);
	return (0);
}

static int pad_12()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("520       ", r);
	return (0);
}

static int pad_13()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520      ", r);
	return (0);
}

static int pad_14()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("520       ", r);
	return (0);
}

static int pad_15()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = -1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520", r);
	return (0);
}

static int pad_16()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 1;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = -1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("520", r);
	return (0);
}

static int pad_17()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 1;
	t->attr_space = 0;
	t->length_field = -1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS(s, r);
	return (0);
}

static int pad_18()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = -1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-520", r);
	return (0);
}

static int pad_19()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = -1;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS(" 520", r);
	return (0);
}

static int pad_20()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("-000000520", r);
	return (0);
}

static int pad_21()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = -1;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS(" 000000520", r);
	return (0);
}

static int pad_22()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("    -00520", r);
	return (0);
}

static int pad_23()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("     00520", r);
	return (0);
}

static int pad_24()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("    -00520", r);
	return (0);
}

static int pad_25()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 0;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 1;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("     00520", r);
	return (0);
}

static int pad_26()
{
	char *s = "520";
	long long int l = -520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("    -00520", r);
	return (0);
}

static int pad_27()
{
	char *s = "520";
	long long int l = 520;
	char *r;
	t_format *t = init_struct();
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	s = param_precision_d(t->precision, l, s);
	r = param_attribut_d(t, l, s);
	RS("    +00520", r);
	return (0);
}

static int pad_test()
{
	PT;
	_verify(pad_01);
	_verify(pad_02);
	_verify(pad_03);
	_verify(pad_04);
	_verify(pad_05);
	_verify(pad_06);
	_verify(pad_07);
	_verify(pad_08);
	_verify(pad_09);
	_verify(pad_10);
	_verify(pad_11);
	_verify(pad_12);
	_verify(pad_13);
	_verify(pad_14);
	_verify(pad_15);
	_verify(pad_16);
	_verify(pad_17);
	_verify(pad_18);
	_verify(pad_19);
	_verify(pad_20);
	_verify(pad_21);
	_verify(pad_22);
	_verify(pad_23);
	_verify(pad_24);
	_verify(pad_25);
	_verify(pad_26);
	_verify(pad_27);
	return (0);
}

static int cfd_01_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_none;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    +00520", r);
	return (0);
}

static int cfd_01()
{
	cfd_01_(0, 520);
	return (0);
}

static int cfd_02_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_none;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    -00520", r);
	return (0);
}

static int cfd_02()
{
	cfd_02_(0, -520);
	return (0);
}

static int cfd_03_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_hh;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    +00008", r);
	return (0);
}

static int cfd_03()
{
	cfd_03_(0, 520);
	return (0);
}

static int cfd_04_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_hh;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    -00008", r);
	return (0);
}

static int cfd_04()
{
	cfd_04_(0, -520);
	return (0);
}

static int cfd_05_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_h;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    -04288", r);
	return (0);
}

static int cfd_05()
{
	cfd_05_(0, 520000);
	return (0);
}

static int cfd_06_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_h;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("    +04288", r);
	return (0);
}

static int cfd_06()
{
	cfd_06_(0, -520000);
	return (0);
}

static int cfd_07_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_ll;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("+1371543787226005504", r);
	return (0);
}

/*
static int cfd_07()
{
	cfd_07_(0, -52000000000000000000000);
	return (0);
}*/

static int cfd_08_(int n, ...)
{
	char *r;
	va_list ap;
	va_start(ap, n);
	t_format *t = init_struct();
	va_copy(t->arg, ap);
	t->length_type = code_ll;
	t->precision = 5;
	t->attr_0 = 1;
	t->attr_plus = 1;
	t->attr_moins = 0;
	t->attr_dieze = 0;
	t->attr_space = 0;
	t->length_field = 10;
	r = conv_format_d(t);
	RS("-1371543787226005504", r);
	return (0);
}

/*
static int cfd_08()
{
	cfd_08_(0, 52000000000000000000000);
	return (0);
}*/

static int cfd_test()
{
	PT;
	_verify(cfd_01);
	_verify(cfd_02);
	_verify(cfd_03);
	_verify(cfd_04);
	_verify(cfd_05);
	_verify(cfd_06);
	//_verify(cfd_07);
	//_verify(cfd_08);
	return (0);
}

int		format_d_test()
{
	return (ppd_test() + pad_test() + cfd_test());
}
