/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:51:18 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 15:51:19 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typing_j(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_lltoa((intmax_t)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((uintmax_t)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("x", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((uintmax_t) conv->type),
				"0123456789", "0123456789abcdef");
	}
	else if (ft_strchr("X", conv->type_letter))
	{
		conv->typing = ft_convert_base(
				ft_ulltoa((uintmax_t) conv->type),
				"0123456789", "0123456789ABCDEF");
	}
	else
		return (0);
	return (1);
}
