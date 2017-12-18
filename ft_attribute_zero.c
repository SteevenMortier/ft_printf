/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:41:06 by smortier          #+#    #+#             */
/*   Updated: 2017/12/04 16:17:05 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define CHAR conv->final_arg[index] ==

int		ft_spot_attribute(t_conv *conv)
{
	int		index;

	index = -1;
	while (conv->first_arg[++index])
	{
		if (conv->first_arg[index] >= '1' && conv->first_arg[index] <= '9')
			break;
		if (conv->first_arg[index] == '0')
			return (1);
	}
	return (0);
}

void	ft_hold_attribute_zero(t_conv *conv, char *space_or_no)
{
	int		index;

	if (!space_or_no)
	{
		index = -1;
		while (conv->final_arg[++index] && (CHAR ' ' || CHAR '+' || CHAR '-'))
		{
			if (ft_strchr("-+", conv->final_arg[index]))
				conv->final_arg[0] = conv->final_arg[index];
			conv->final_arg[index] = ((CHAR '+' || CHAR '-') &&
									  !index) ? conv->final_arg[index] : '0';
		}
	}
	else
	{
		index = 0;
		while (conv->final_arg[++index] && (CHAR ' ' || CHAR '+' || CHAR '-'))
		{
			if (ft_strchr("+-", conv->final_arg[index]))
				conv->final_arg[0] = conv->final_arg[index];
			conv->final_arg[index] = ((CHAR '+' || CHAR '-') &&
					!index) ? conv->final_arg[index] : '0';
		}
	}
}

void	ft_hold_attribute_zro_prc(t_conv *conv)
{
	int		index;

	index = -1;
	while (conv->final_arg[++index] && conv->final_arg[index] == ' ')
	{
		if (ft_strchr("+-", conv->final_arg[index]))
			conv->final_arg[0] = conv->final_arg[index];
		conv->final_arg[index] = '0';
	}
}

void	ft_hold_zro_withxX(t_conv *conv)
{
	int		index;

	index = -1;
	while (conv->final_arg[++index] && (CHAR ' ' || CHAR 'x' || CHAR 'X' ||
			CHAR '0'))
	{
		if (CHAR 'X' || CHAR 'x')
			conv->final_arg[1] = conv->final_arg[index];
		conv->final_arg[index] = '0';
	}
}

void	ft_attribute_zero(t_conv *conv)
{
	while (conv)
	{
		if (ft_spot_attribute(conv) && !conv->precision &&
				!ft_strchr(conv->first_arg, '-'))
		{
			if (conv->type_letter == 'x' || conv->type_letter == 'X')
				ft_hold_zro_withxX(conv);
			else if (conv->type_letter != '%')
				ft_hold_attribute_zero(conv, ft_strchr(conv->first_arg, ' '));
			else if (conv->type_letter == '%')
				ft_hold_attribute_zro_prc(conv);
		}
		conv = conv->next;
	}
}
