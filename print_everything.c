/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:08:07 by smortier          #+#    #+#             */
/*   Updated: 2018/01/10 20:08:09 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		help_for_norm(t_conv *conv)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (conv->type_letter != 'C' && conv->type_letter != 'S')
	{
		ft_putstr(conv->final_arg);
		ret += (int)ft_strlen(conv->final_arg);
	}
	else if (conv->type_letter == 'C' || (conv->type_letter == 'S'))
	{
		if (conv->type)
			ret += ft_print_unicode(conv);
		else
			ret++;
	}
	return (ret);
}

int		null_case(void)
{
	int		ret;

	ret = 0;
	ft_putstr("(null)");
	ret += ft_strlen("(null)");
	return (ret);
}

int		norme_helper(t_conv *conv)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (!ft_strchr(conv->first_arg, '.'))
	{
		while (++i < (int)ft_strlen(conv->final_arg) - 1)
			(ft_strchr(conv->first_arg, '0') ? ft_putchar('0')
											: ft_putchar(' '));
	}
	ft_putchar(conv->final_arg[ft_strlen(conv->final_arg)]);
	ret += (conv->lenght_min) ? (int)ft_strlen(conv->final_arg) :
		1;
	return (ret);
}

int		print_everything(t_conv *conv)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (conv)
	{
		if (!conv->type && ft_strchr("sS", conv->type_letter) &&
			conv->type_letter)
			ret += null_case();
		else if ((conv->type_letter == 'c' && !conv->type))
			ret += norme_helper(conv);
		else
			ret += help_for_norm(conv);
		conv = conv->next;
	}
	return (ret);
}
