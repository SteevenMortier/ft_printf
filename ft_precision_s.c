/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:17:26 by smortier          #+#    #+#             */
/*   Updated: 2017/12/13 19:40:59 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE ft_strlen(conv->final_arg)

void		ft_push_str_end3(t_conv *conv, int size)
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

void		ft_cut_end(t_conv *conv)
{
	int		i;
	int		y;

	conv->typing[conv->precision] = '\0';
	i = 0;
	while (i < (int)(conv->lenght_min - ft_strlen(conv->typing)))
	{
		conv->final_arg[i] = ' ';
		i++;
	}
	y = 0;
	while (i + y != (int)conv->lenght_min)
	{
		conv->final_arg[i + y] = conv->typing[y];
		y++;
	}
	conv->final_arg[i + y] = '\0';
}

void		ft_precision_s(t_conv *conv)
{
	if (conv->lenght_min > ft_strlen(conv->typing) && conv->lenght_min)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg, SIZE,
									 conv->lenght_min);
		ft_push_str_end3(conv, (int)conv->lenght_min);
	}
	if (conv->precision < ft_strlen(conv->typing) && conv->precision)
	{
		if (conv->lenght_min)
			ft_cut_end(conv);
		else
			conv->final_arg[conv->precision] = '\0';
	}
}
