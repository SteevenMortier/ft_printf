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

#define  __TEST__ "Test -> {%d}\n", 42

int		main(void)
{
	int ret;
	ret = ft_printf("\e[1m\e[93m\t\e[4m[FT_PRINTF]\e[0m\t"__TEST__);
//	printf("Return [ft_printf] > {%d}\n",ret);
	ret = printf("\e[1m\e[38;5;82m\t\e[4m[PRINTF]\e[0m\t"__TEST__);
//	printf("Return [printf] > {%d}\n",ret);
	return (0);
}