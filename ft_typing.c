/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:22:44 by smortier          #+#    #+#             */
/*   Updated: 2017/12/01 19:22:45 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_typing(t_conv *conv, va_list arg)
{
	int		i;

	i = -1;
	while (conv)
	{
		if (conv->type_letter && conv->type_letter != '5')
			conv->type = va_arg(arg, void *);
		if (conv->type_letter == '5')
		{
			if (conv->first_arg[0] != '%')
			{
				while (ft_isdigit(conv->first_arg[++i]) ||
									ft_strchr("+-. ", conv->first_arg[i]))
					;
				conv->type = ft_strsub(conv->first_arg, i,
										ft_strlen(conv->first_arg) - i);
			}
			else
				conv->type = ft_strdup("%");
			conv->type_letter = 's';
			conv->modified = 1;
		}
		conv = conv->next;
	}
	va_end(arg);
}
