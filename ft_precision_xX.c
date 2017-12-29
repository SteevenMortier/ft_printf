/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_xX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:41:13 by smortier          #+#    #+#             */
/*   Updated: 2017/12/13 17:41:15 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#define SIZE ft_strlen(conv->final_arg)
#define CHAR conv->final_arg[i] ==
#define CHARY conv->final_arg[y] ==
#define CHARI2 conv->final_arg[i + 1] ==

void		ft_push_str_end2(t_conv *conv, int size)
{
	int		i;
	int		y;

	i = size - 1;
	while (i != -1)
	{
		y = i;
		while (!conv->final_arg[y] && y != 0)
			y--;
		conv->final_arg[i] = conv->final_arg[y];
		conv->final_arg[y] = '\0';
		i--;
	}
	while (++i < size)
		if (!conv->final_arg[i])
			conv->final_arg[i] = ' ';
}

void		ft_hold_precision2(t_conv *conv)
{
	int		i;
	int		y;

	if (conv->lenght_min > conv->precision)
		i = conv->lenght_min - conv->precision;
	else
		i = 0;
	y = i;
	while (conv->final_arg[++y])
	{
		if (CHARY 'x' || CHARY 'X')
		{
			conv->final_arg[i] = conv->final_arg[y - 1];
			conv->final_arg[i + 1] = conv->final_arg[y];
		}
	}
	if (conv->lenght_min > conv->precision)
		i = conv->lenght_min - conv->precision;
	else
		i = 0;
	if (CHARI2 'x' || CHARI2 'X')
		i += 2;
	while (!(CHAR '\0') && (CHAR ' ' || CHAR '0' || CHAR 'x' || CHAR 'X'))
	{
		if (CHAR ' ' || CHAR 'x' || CHAR 'X')
			conv->final_arg[i] = '0';
		i++;
	}
}

void		ft_jsp(t_conv *conv)
{
	int		i;

	if (conv->lenght_min > ft_strlen(conv->final_arg) &&
		conv->lenght_min > conv->precision)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
									 SIZE, conv->lenght_min);
		ft_push_str_end2(conv, (int)conv->lenght_min);
	}
	i = -1;
	if (conv->precision)
	{
		while (conv->final_arg[++i])
		{
			if (CHAR 'x' || CHAR 'X')
			conv->precision += 2;
		}
		if (conv->precision >= SIZE)
		{
			conv->final_arg = ft_realloc((void **)&conv->final_arg,
										 SIZE, conv->precision);
			if (conv->lenght_min < conv->precision)
				ft_push_str_end2(conv, conv->precision);
		}
		ft_hold_precision2(conv);
	}
}

void		ft_precision_xX(t_conv *conv)
{
	ft_jsp(conv);
}
