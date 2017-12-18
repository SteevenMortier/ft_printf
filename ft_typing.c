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
	//Need a parsing here
	while (conv)
	{
		if (conv->type_letter && conv->type_letter != '%')
			conv->type = va_arg(arg, void *);
		conv = conv->next;
	}
	va_end(arg);
}