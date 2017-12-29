/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_htag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:40:48 by smortier          #+#    #+#             */
/*   Updated: 2017/12/03 17:40:49 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define STR conv->final_arg
#define CCHR conv->type_letter ==

void		ft_attribute_htag(t_conv *conv)
{
	int		i;
	int		y;

	if ((CCHR 'o' || CCHR 'x' || CCHR 'X' || CCHR 'O') || CCHR 'p')
		conv->final_arg = ft_strnew((ft_strlen(conv->typing) + 2));
	else
		return ;
	if (ft_strlen(conv->typing) == 1 && conv->typing[0] == '0' && !(CCHR 'p'))
	{
		STR[0] = '0';
		return ;
	}
	i = 0;
	y = 0;
	while ((unsigned long)i < ft_strlen(conv->typing) + 2)
	{
		if (i == 0)
			STR[i] = '0';
		else if (i == 1 && (conv->type_letter == 'x' || conv->type_letter == 'p'))
			STR[i]  = 'x';
		else if (i == 1 && conv->type_letter == 'X')
			STR[i] = 'X';
		else
		{
			STR[i] = conv->typing[y];
			y++;
		}
		i++;
	}
}
