/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_holder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:37:15 by smortier          #+#    #+#             */
/*   Updated: 2017/12/11 22:37:16 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE ft_strlen(conv->final_arg)
#define CHAR conv->final_arg[i] ==
#define CHARY conv->final_arg[y] ==
#define CHARI2 conv->final_arg[i + 1] ==

void	ft_replace_points_by_space(t_conv *conv)
{
	int		i;

	i = -1;
	while (conv->final_arg[++i])
		if (CHAR '.')
			conv->final_arg[i] = ' ';
}

void		ft_push_str_end(t_conv *conv, int size)
{
	int		i;
	int		y;

	i = size - 1;
	while (i != -1)
	{
		y = i;
		while (!conv->final_arg[y] && y != 0)
			y--;
		if (CHARY 'x' || CHARY 'X')
			i -= 1;
		conv->final_arg[i] = conv->final_arg[y];
		conv->final_arg[y] = '\0';
		i--;
	}
	while (++i < size)
		if (!conv->final_arg[i])
			conv->final_arg[i] = '.';
}

void		ft_hold_precision(t_conv *conv)
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
		if (CHARY ' ' || CHARY '-' || CHARY '+')
			conv->final_arg[i] = conv->final_arg[y];
	}
	if (conv->lenght_min > conv->precision)
		i = conv->lenght_min - conv->precision;
	else
		i = 0;
	if (CHAR ' ' || CHAR '-' || CHAR '+')
		i += 1;
	while (!(CHAR '\0')&& (CHAR ' ' || CHAR '.' || CHAR '-' || CHAR '+'))
	{
		conv->final_arg[i] = '0';
		i++;
	}
}

void		ft_existprec(t_conv *conv)
{
	int		i;

	if (conv->lenght_min > ft_strlen(conv->final_arg) &&
			conv->lenght_min >= conv->precision && conv->lenght_min)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
									 SIZE, conv->lenght_min);
		ft_push_str_end(conv, (int)conv->lenght_min);
	}
	i = -1;
	if (conv->precision)
	{
		while (conv->final_arg[++i])
		{
			if (CHAR ' ' || CHAR '-' || CHAR '+')
				conv->precision += 1;
		}
		if (conv->precision > SIZE)
		{
			conv->final_arg = ft_realloc((void **)&conv->final_arg,
										 SIZE, conv->precision);
			if (conv->lenght_min < conv->precision)
				ft_push_str_end(conv, conv->precision);
		}
		ft_hold_precision(conv);
	}
	if (conv->lenght_min || conv->precision)
		ft_replace_points_by_space(conv);
}

void		ft_precision_holder(t_conv *conv)
{
	if (conv->type_letter == '%')
		ft_precision_pourcent(conv);
	else if (conv->type_letter == 's')
		ft_precision_s(conv);
	else if (ft_strchr(conv->final_arg, 'X') || ft_strchr(conv->final_arg, 'x'))
		ft_precision_xX(conv);
	else
		ft_existprec(conv);
}
