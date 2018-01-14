/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks_holder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:02:50 by smortier          #+#    #+#             */
/*   Updated: 2018/01/14 22:02:53 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_leaks_holder(t_conv *conv)
{
	{
		t_conv        *temp;
		if (conv)
		{
			while (conv)
			{
				temp = conv;
				conv = conv->next;
				ft_memdel((void **)&temp->first_arg);
				ft_memdel((void **)&temp->typing);
				ft_memdel((void **)&temp->final_arg);
				ft_memdel((void **)&temp->specifier);
				ft_memdel((void **)&temp->type);
				ft_memdel((void **)&temp);
			}
			return (1);
		}
		return (0);
	}
/*	if (!conv)
		return (0);
	while (conv->next)
	{
		if (conv->type_letter)
		{
			if (conv->modified)
				ft_memdel(&conv->type);
			ft_memdel((void **)&conv->typing);
			if (conv->type_letter == 'C')
				ft_memdel((void **)&conv->final_argw);
			ft_memdel((void **)&conv->final_arg);
		}
		ft_memdel((void **)&conv->first_arg);
		conv = conv->next;
	}
	if (conv->type_letter)
	{
		if (conv->modified)
			ft_memdel(&conv->type);
		if (conv->type_letter == 'C') {
			ft_memdel((void **)&conv->final_argw);
		}
	}
	ft_memdel((void **)&conv->typing);
	ft_memdel((void **)&conv->final_arg);
	ft_memdel((void **)&conv->first_arg);
	while (conv->prev)
	{
		conv = conv->prev;
		ft_memdel((void **)&conv->next);
	}
	ft_memdel((void **)&conv);
	return (1);*/
}
