/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:53:17 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 16:53:19 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	normal_typing(t_conv *conv)
{
	if (ft_strchr("di", conv->type_letter))
		conv->typing = ft_strdup(ft_itoa((int)conv->type));
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_itoa((unsigned int)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("c", conv->type_letter))
	{
		conv->typing = ft_strnew(1);
		conv->typing[0] = (int)conv->type;
	}
	else if (ft_strchr("s", conv->type_letter))
		conv->typing = ft_strdup((char *) conv->type);
	else if (ft_strchr("x", conv->type_letter))
		conv->typing = ft_strdup(ft_convert_base(
				ft_itoa((unsigned int)conv->type),
				"0123456789", "0123456789abcdef"));
	else if (ft_strchr("X", conv->type_letter))
		conv->typing = ft_strdup(ft_convert_base(
				ft_itoa((unsigned int)conv->type),
				"0123456789", "0123456789ABCDEF"));
}

void	which_one_2(t_conv *conv)
{
	if (!ft_strcmp(conv->specifier, "j"))
	{
		if (!ft_typing_j(conv))
			normal_typing(conv);
	}
	else if (!ft_strcmp(conv->specifier, "z"))
	{
		if (!ft_typing_z(conv))
			normal_typing(conv);
	}
}

void	which_one(t_conv *conv)
{
	if (!ft_strcmp(conv->specifier, "hh"))
	{
		if (!ft_typing_hh(conv))
			normal_typing(conv);
	}
	else if (!ft_strcmp(conv->specifier, "h"))
	{
		if (!ft_typing_h(conv))
			normal_typing(conv);
	}
	else if (!ft_strcmp(conv->specifier, "ll"))
	{
		if (!ft_typing_ll(conv))
			normal_typing(conv);
	}
	else if (!ft_strcmp(conv->specifier, "l"))
	{
		if (!ft_typing_l(conv))
			normal_typing(conv);
	}
	else
		which_one_2(conv);
}

void	ft_typing_to_str(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
		{
			if (conv->specifier)
				which_one(conv);
			else
				normal_typing(conv);
		}
		conv = conv->next;
	}
}
