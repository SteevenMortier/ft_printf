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
		conv->typing = ft_itoa((int)conv->type);
	else if (ft_strchr("o", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned int)conv->type),
				"0123456789", "01234567");
	else if (ft_strchr("c", conv->type_letter))
	{
		conv->typing = ft_strnew(1);
		conv->typing[0] = (char)conv->type;
	}
	else if (conv->type_letter == '%')
		conv->typing = "%";
	else if (ft_strchr("s", conv->type_letter))
		conv->typing = ft_strdup((char *) conv->type);
	else if (ft_strchr("u", conv->type_letter))
		conv->typing = ft_ulltoa((unsigned int)conv->type);
	else if (ft_strchr("x", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned int)conv->type),
				"0123456789", "0123456789abcdef");
	else if (ft_strchr("X", conv->type_letter))
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned int)conv->type),
				"0123456789", "0123456789ABCDEF");
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

char	*convert_to_utf_eight(unsigned int c)
{
	char *string = ft_strnew(4);

	if (c < 0x80)
		string[0] = (c >> 0 & 0x7F) | 0x00;
	else if (c < 0x0800)
	{
		string[0] = (c >> 6  & 0x1F) | 0xC0;
		string[1] = (c >> 0  & 0x3F) | 0x80;
	}
	else if (c < 0x010000)
	{
		string[0] = (c >> 12 & 0x0F) | 0xE0;
		string[1] = (c >> 6  & 0x3F) | 0x80;
		string[2] = (c >> 0  & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		string[0] = (c >> 18 & 0x07) | 0xF0;
		string[1] = (c >> 12 & 0x3F) | 0x80;
		string[2] = (c >> 6  & 0x3F) | 0x80;
		string[3] = (c >> 0  & 0x3F) | 0x80;
	}
	return (string);
}

void	ft_hold_maj(t_conv *conv)
{
	if (conv->type_letter == 'S')
	{
		int i = 0;
		wchar_t *test = (wchar_t *)conv->type;
		while (test[i])
		{
			ft_putstr(convert_to_utf_eight(test[i]));
			i++;
		}
	}
	else if (conv->type_letter == 'C')
	{
		conv->typing = convert_to_utf_eight((int)conv->type);
	}
	else if (ft_strchr("DI", conv->type_letter))
		conv->typing = ft_lltoa((long long int)conv->type);
	else if (conv->type_letter == 'O')
		conv->typing = ft_convert_base(
				ft_ulltoa((unsigned long long int)conv->type), "0123456789",
				"01234567");
	else
	conv->typing = ft_ulltoa((unsigned long long int)conv->type);
}

void	ft_typing_to_str(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
		{
			if (conv->type_letter <= 90 && conv->type_letter >= 65 &&
					conv->type_letter != 'X')
				ft_hold_maj(conv);
			else if (conv->type_letter == 'p')
				conv->typing = ft_convert_base(
						ft_ulltoa((unsigned long int)(conv->type)),
						"0123456789", "0123456789abcdef");
			else if (conv->specifier)
				which_one(conv);
			else
				normal_typing(conv);
		}
		conv = conv->next;
	}
}
