/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:32:27 by smortier          #+#    #+#             */
/*   Updated: 2017/11/30 16:32:31 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define  __TEST__ "%zi", LLONG_MIN
int		main(void)
{
//	int ret;
//	char c;
//	setlocale(LC_ALL, "");
//	ret = ft_printf(/*"\e[1m\e[93m\t\e[4m[FT_PRINTF]\e[0m\t"*/__TEST__);
//	printf("Return [ft_printf] > {%d}\n",ret);
//	ret = printf(/*"\e[1m\e[38;5;82m\t\e[4m[PRINTF]\e[0m\t"*/__TEST__);
//	printf("Return [printf] > {%d}\n",ret);
//	return (0);*/
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	ft_printf("");
	ft_printf("%.X, %.0X\n", 0, 0);
	printf("%.X, %.0X\n", 0, 0);
	ft_printf("{%+03d}\n", 123456);
	printf("{%+03d}", 123456);
//	while (1);
	return (0);
}