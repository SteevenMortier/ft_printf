/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spot_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:22:17 by smortier          #+#    #+#             */
/*   Updated: 2017/12/01 16:22:19 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_spot_converter(char c)
{
	if (!ft_strchr("sSpdDioOuUxXcC", c))
	{
		return (0);
	}
	return (1);
}