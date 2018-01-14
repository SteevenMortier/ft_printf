/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:41:43 by smortier          #+#    #+#             */
/*   Updated: 2017/12/03 17:41:44 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_dexist(t_conv *conv)
{
	int		i;

	if (conv->typing[0] == '-')
	{
		conv->final_arg = ft_strdup(conv->typing);
		return ;
	}
	else
		conv->final_arg = ft_strnew(ft_strlen(conv->typing + 1));
	i = 1;
	conv->final_arg[0] = ' ';
	while (conv->typing[i - 1])
	{
		conv->final_arg[i] = conv->typing[i - 1];
		i++;
	}
}

void		ft_attribute_space(t_conv *conv)
{
	if (ft_strchr(conv->first_arg, '+'))
		return ;
	if (!conv->final_arg)
		ft_dexist(conv);
	else
		exit(1);
}
