/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_holder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:37:15 by smortier          #+#    #+#             */
/*   Updated: 2017/12/11 22:37:16 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_existprec(t_conv *conv)
{
	(void)conv;
}

void		ft_dexistprec(t_conv *conv)
{
	(void)conv;
}

void		ft_precision_holder(t_conv *conv)
{
	if (!conv->final_arg)
		ft_dexistprec(conv);
	else
		ft_existprec(conv);
}
