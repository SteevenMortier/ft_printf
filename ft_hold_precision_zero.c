/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_precision_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:54:04 by smortier          #+#    #+#             */
/*   Updated: 2017/12/20 17:00:18 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_point_case(t_conv *conv)
{
	if (conv->type_letter == 'o' && ft_strchr(conv->first_arg, '#'))
		conv->final_arg[0] = '0';
	else
	{
		ft_memdel((void **)conv->final_arg);
		conv->final_arg = NULL;
	}
}

void		ft_hold_for_case(t_conv *conv)
{
	int		i;

	if (conv->precision == 0 && !conv->lenght_min && !(long long int)conv->type)
	{
		ft_memdel((void **)&conv->final_arg);
		conv->final_arg = NULL;
	}
	if (conv->precision == 0 && !conv->lenght_min && !(long long int)conv->type
		&& conv->type_letter != 'd')
	{
		conv->final_arg = ft_strnew(1);
		if (ft_strchr(conv->first_arg, '.'))
			ft_point_case(conv);
		else
			conv->final_arg[0] = '0';
	}
	else if (!conv->precision && conv->lenght_min && !(long long int)conv->type)
	{
		i = -1;
		while (conv->final_arg[++i])
			if (conv->final_arg[i] != ' ')
				conv->final_arg[i] = ' ';
	}
}

void		ft_hold_precision_zero(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter == 'd' && !ft_strchr(conv->first_arg, '.')
			&& !(long long int)conv->type)
			;
		else if (ft_strchr("diuoxX", conv->type_letter) && conv->type_letter)
			ft_hold_for_case(conv);
//		else if (conv->type_letter == 'p' && !conv->type && !conv->precision)
//			conv->final_arg[ft_strlen(conv->final_arg) - 1] = '\0';
		conv = conv->next;
	}
}
