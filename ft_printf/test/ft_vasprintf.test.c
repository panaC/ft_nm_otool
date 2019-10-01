/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:10 by pleroux           #+#    #+#             */
/*   Updated: 2018/03/15 14:14:29 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static int		vpf_01_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("allo42 : sinon -42, finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_01()
{
	return (vpf_01_("allo%d : sinon %d, finish", 42, -42));
}

static int		vpf_02_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("allo42 : sinon -42, finish420000000000", s);
	va_end(ap);
	return (0);
}

static int		vpf_02()
{
	return (vpf_02_("allo%d : sinon %d, finish%D", 42, -42, 420000000000));
}

static int		vpf_03_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("alloalloollaallo\nallllllllllllo\tollllllllla", s);
	va_end(ap);
	return (0);
}

static int		vpf_03()
{
	return (vpf_03_("alloalloollaallo\nallllllllllllo\tollllllllla"));
}

static int		vpf_04_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 0x2a, finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_04()
{
	return (vpf_04_("test x %#x, finish", 42));
}

static int		vpf_05_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 0X0002A   , finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_05()
{
	return (vpf_05_("test x %#0+- 10.5X, finish", 42));
}

static int		vpf_06_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	ft_vasprintf(&s, e, ap);
	RS("test x 00052     , finish", s);
	va_end(ap);
	return (0);
}

static int		vpf_06()
{
	return (vpf_06_("test x %#0+- 10.5o, finish", 42));
}

static int		vpf_07_(int *p, char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %p, finish", p);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_07()
{
	int		p;
	return (vpf_07_(&p, "test x %p, finish", &p));
}

static int		vpf_08_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %c, finish", 'h');
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_08()
{
	int		p;
	return (vpf_08_("test x %c, finish", 'h'));
}

#include <wchar.h>
#include <unistd.h>
#include <locale.h>

static int		vpf_09_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %C, finish", (wint_t)536);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_09()
{
	int		p;
	return (vpf_09_("test x %C, finish", (wint_t)536));
}

static int		vpf_10_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %-10C, finish", (wint_t)536);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_10()
{
	int		p;
	return (vpf_10_("test x %-10C, finish", (wint_t)536));
}

static int		vpf_11_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %s, finish", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_11()
{
	int		p;
	return (vpf_11_("test x %s, finish", NULL));
}

static int		vpf_12_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %10.3s, finish", "Hello");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_12()
{
	int		p;
	return (vpf_12_("test x %10.3s, finish", "Hello"));
}

static int		vpf_13_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %s, finish", "Hello");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_13()
{
	int		p;
	return (vpf_13_("test x %s, finish", "Hello"));
}

static int		vpf_14_(char *e, ...)
{
	wint_t		t[5] = {536,537,538,539,0};
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %S, finish", t);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_14()
{
	int		p;
	wint_t		t[5] = {536,537,538,539,0};
	return (vpf_14_("test x %S, finish", t));
}

static int		vpf_15_(char *e, ...)
{
	wint_t		t[5] = {536,537,538,539,0};
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %15.2S, finish", t);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_15()
{
	int		p;
	wint_t		t[5] = {536,537,538,539,0};
	return (vpf_15_("test x %15.2S, finish", t));
}

static int		vpf_16_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %p, finish", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_16()
{
	return (vpf_16_("test x %p, finish", NULL));
}

static int		vpf_17_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test x %-10.5%, finish");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_17()
{
	return (vpf_17_("test x %-10.5%, finish"));
}

static int		vpf_18_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%dtest x %-10.5%, finish%d", 15, 42);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_18()
{
	return (vpf_18_("%dtest x %-10.5%, finish%d", 15, 42));
}

static int		vpf_19_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%20p", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_19()
{
	return (vpf_19_("%20p", NULL));
}

static int		vpf_20_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%d", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_20()
{
	return (vpf_20_("%d", 0));
}

static int		vpf_21_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "% d", 0xff11ff);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_21()
{
	return (vpf_21_("% d", 0xff11ff));
}

static int		vpf_22_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "\ntoto et %00009Uallo%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_22()
{
	return (vpf_22_("\ntoto et %00009Uallo%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200));
}

static int		vpf_23_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%#o", 1000);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_23()
{
	return (vpf_23_("%#o", 1000));
}

static int		vpf_24_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_24()
{
	return (vpf_24_("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
}

static int		vpf_25_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%#X", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_25()
{
	return (vpf_25_("%d", 0));
}

static int		vpf_26_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%p", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_26()
{
	return (vpf_26_("%p", 0));
}

static int		vpf_27_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%c", '\0');
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_27()
{
	return (vpf_27_("%c", '\0'));
}

static int		vpf_28_(char *e, ...)
{
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%.2s", NULL);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_28()
{
	return (vpf_28_("%.2s", NULL));
}

static int		vpf_29_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%C", 0xd800);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_29()
{
	return (vpf_29_("%C", 0xd800));
}

static int		vpf_30_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%C", (wint_t)-2);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_30()
{
	return (vpf_30_("%C", (wint_t)-2));
}

static int		vpf_31_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_31()
{
	return (vpf_31_("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));
}

static int		vpf_32_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	ft_vasprintf(&s, e, ap);
	sprintf(vp, "%c", -21);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_32()
{
	return (vpf_32_("%c", -21));
}

static int		vpf_33_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_33()
{
	return (vpf_33_("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
}

static int		vpf_34_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "@moulitest: %#.o %#.0o", 0, 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_34()
{
	return (vpf_34_("@moulitest: %#.o %#.0o", 0, 0));
}

static int		vpf_35_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "% Zoooo", 42);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_35()
{
	return (vpf_35_("% Zoooo", 42));
}

static int		vpf_36_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "allo%#0 +- +      20ma", 0, 42);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_36()
{
	return (vpf_36_("allo%#0 +- +      20ma", 0, 42));
}

static int		vpf_37_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "%");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_37()
{
	return (vpf_37_("%"));
}

static int		vpf_38_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "{%}");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_38()
{
	return (vpf_38_("{%}"));
}

static int		vpf_39_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "{%10R}");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_39()
{
	return (vpf_39_("{%10R}"));
}

static int		vpf_40_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "%c", 200);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_40()
{
	return (vpf_40_("%c", 200));
}

static int		vpf_41_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "{%03c}", 0);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_41()
{
	return (vpf_41_("{%03c}", 0));
}

static int		vpf_42_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "{%05s}", "abc");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_42()
{
	return (vpf_42_("{%05s}", "abc"));
}

static int		vpf_43_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%S", NULL);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_43()
{
	return (vpf_43_("%S", NULL));
}

static int		vpf_44_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "% S", NULL);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_44()
{
	return (vpf_44_("% S", NULL));
}

static int		vpf_45_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%lc", 0x4e6);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_45()
{
	return (vpf_45_("%lc", 0x4e6));
}


static int		vpf_46_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%C", 0xbffe);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_46()
{
	return (vpf_46_("%C", 0xbffe));
}


static int		vpf_47_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%lc", 254);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_47()
{
	return (vpf_47_("%lc", 254));
}

static int		vpf_48_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%-1C", 2250);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_48()
{
	return (vpf_48_("%-1C", 2250));
}

/*static int		vpf_45_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	val_r = sprintf(vp, "%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_45()
{
	return (vpf_43_("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
}*/

static int		vpf_50_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%S", L"");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_50()
{
	return (vpf_50_("%S", L""));
}


static int		vpf_49_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", 
			L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
			L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ",
			L"Ψ ψ", L"Ω ω", L"");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_49()
{
	return (vpf_49_("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β",
				L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
 				L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ",
				L"Ψ ψ", L"Ω ω", L""));
}

static int		vpf_51_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%lc, %lc", L'暖', L'ح');
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_51()
{
	return (vpf_51_("%lc, %lc", L'暖', L'ح'));
}

static int		vpf_52_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "{%30S}", L"我是一只猫。");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_52()
{
	return (vpf_52_("{%30S}", L"我是一只猫。"));
}

static int		vpf_53_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "{%30s}", "hello");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_53()
{
	return (vpf_53_("{%30s}", "hello"));
}

static int		vpf_54_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_54()
{
	return (vpf_54_("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
}

static int		vpf_55_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "{%05.Z}", 0);
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_55()
{
	return (vpf_55_("{%05.Z}", 0));
}

static int		vpf_56_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "{%05.S}", L"42 c est cool");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_56()
{
	return (vpf_56_("{%05.S}", L"42 c est cool"));
}

static int		vpf_57_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%.4S", L"我是一只猫。");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_57()
{
	return (vpf_57_("%.4S", L"我是一只猫。"));
}

static int		vpf_58_(char *e, ...)
{
	setlocale(LC_ALL, "");
	va_list ap;
	va_start(ap, e);
	char *s;
	char *vp = ft_strnew(100);
	int val_r;
	val_r = ft_vasprintf(&s, e, ap);
	printf("ret %d\n", val_r);
	val_r = sprintf(vp, "%4.1S", L"Jambon");
	printf("ret %d\n", val_r);
	RS(vp, s);
	va_end(ap);
	return (0);
}

static int		vpf_58()
{
	return (vpf_58_("%4.1S", L"Jambon"));
}

int ft_vasprintf_test()
{
	PT;
	_verify(vpf_01);
	_verify(vpf_02);
	_verify(vpf_03);
	_verify(vpf_04);
	_verify(vpf_05);
	_verify(vpf_06);
	_verify(vpf_07);
	_verify(vpf_08);
	_verify(vpf_09);
	_verify(vpf_10);
	_verify(vpf_11);
	_verify(vpf_12);
	_verify(vpf_13);
	_verify(vpf_14);
//	_verify(vpf_15);
	_verify(vpf_16);
	_verify(vpf_17);
	_verify(vpf_18);
	_verify(vpf_19);
	_verify(vpf_20);
	_verify(vpf_21);
	_verify(vpf_22);
	_verify(vpf_23);
	_verify(vpf_24);
	_verify(vpf_25);
	_verify(vpf_26);
	_verify(vpf_27);
	_verify(vpf_28);
	_verify(vpf_29);
	_verify(vpf_30);
	_verify(vpf_31);
	_verify(vpf_32);
	_verify(vpf_33);
	_verify(vpf_34);
	_verify(vpf_35);
	_verify(vpf_36);
	_verify(vpf_37);
	_verify(vpf_38);
	_verify(vpf_39);
	_verify(vpf_40);
	_verify(vpf_41);
	_verify(vpf_42);
	_verify(vpf_43);
	_verify(vpf_44);
	_verify(vpf_45);
	_verify(vpf_46);
	_verify(vpf_47);
	_verify(vpf_48);
	_verify(vpf_50);
//	_verify(vpf_49);
	_verify(vpf_51);
	_verify(vpf_52);
	_verify(vpf_53);
	_verify(vpf_54);
	_verify(vpf_55);
	_verify(vpf_56);
	_verify(vpf_57);
	_verify(vpf_58);
	return (0);
}
