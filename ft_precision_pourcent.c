/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_pourcent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:04:53 by smortier          #+#    #+#             */
/*   Updated: 2017/12/14 20:04:55 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE ft_strlen(conv->final_arg)
#define CHAR conv->final_arg[i] ==
#define CHARY conv->final_arg[y] ==
#define CHARI2 conv->final_arg[i + 1] ==

void	ft_replace_points_by_space_pourcent(t_conv *conv)
{
	int		i;

	i = -1;
	while (conv->final_arg[++i])
		if (CHAR '.')
	conv->final_arg[i] = ' ';
}

void		ft_push_str_end_pourcent(t_conv *conv, int size)
{
	int		i;
	int		y;

	i = size - 1;
	while (i != -1)
	{
		y = i;
		while (!conv->final_arg[y] && y != 0)
			y--;
		conv->final_arg[i] = conv->final_arg[y];
		conv->final_arg[y] = '\0';
		i--;
	}
	while (++i < size)
		if (!conv->final_arg[i])
			conv->final_arg[i] = '.';
}

void		ft_precision_pourcent(t_conv *conv)
{
	if (conv->lenght_min > ft_strlen(conv->final_arg) && conv->lenght_min)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
									 SIZE, conv->lenght_min);
		ft_push_str_end_pourcent(conv, (int)conv->lenght_min);
		ft_replace_points_by_space_pourcent(conv);
	}
}