/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:29:09 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 15:29:10 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typing_hh(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_itoa((signed char)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned char)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("x", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned char)conv->type),
				"0123456789", "0123456789abcdef");
	else if (ft_strchr("X", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned char)conv->type),
				"0123456789", "0123456789ABCDEF");
	else if (conv->type_letter == 'u')
		conv->typing = ft_ulltoa((unsigned char)conv->type);
	else
		return (0);
	return (1);
}