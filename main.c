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

#define  __TEST__ "%x, %x", 0, UINT_MAX

int		main(void)
{
	int ret;
	ret = ft_printf(__TEST__);
	printf("\nReturn [ft_printf] > {%d}\n",ret);
	ret = printf(__TEST__);
	printf("\nReturn [printf] > {%d}\n",ret);
	return (0);
}
