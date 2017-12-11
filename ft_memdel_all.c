/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:24:36 by smortier          #+#    #+#             */
/*   Updated: 2017/12/01 15:24:39 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incude "libft/libft.h"
#include "ft_printf.h"

void 	ft_memdel_all(t_conv *conv)
{
	t_conv	*start;

	start = conv;
	while (conv->next)
	{
		ft_memdel(&conv->first_arg);
		ft_memdel(&conv->final_arg);
		*conv = conv->next;
		if (conv->next == NULL)
		{
			ft_memdel(&conv->next);
			conv = start;
		}
	}
}