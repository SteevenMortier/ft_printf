/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:00:32 by smortier          #+#    #+#             */
/*   Updated: 2017/12/07 18:04:42 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		power(int nbr, int power)
{
	int		res;

	res = nbr;
	if (!power)
		return (1);
	if (power == 1)
		return (nbr);
	while (power > 1)
	{
		res = res * nbr;
		power--;
	}
	return (res);
}

int		convert_b_ten(char *nbr, char *base_from, int neg)
{
	int		i;
	int		len_nbr;
	int		pos_in_base;
	int		res;
	int		len_b_from;

	len_b_from = 0;
	while (base_from[len_b_from])
		len_b_from++;
	len_nbr = -1;
	i = -1;
	i = (neg) ? 0 : -1;
	while (nbr[++i])
		len_nbr++;
	i = (neg) ? 0 : -1;
	res = 0;
	while (nbr[++i] && !(pos_in_base = 0))
	{
		while (nbr[i] != base_from[pos_in_base])
			pos_in_base++;
		res += pos_in_base * power(len_b_from, len_nbr--);
	}
	return (res);
}

int		len_stringh(int base_ten, int len_string, int len_b_to, int neg)
{
	while (base_ten != 0)
	{
		base_ten = base_ten / len_b_to;
		len_string++;
	}
	len_string += neg;
	return (len_string);
}

char	*convert_to_b(char *base_to, int base_ten, int neg)
{
	char	*tab;
	int		tmp;
	int		len_b_to;
	int		len_string;
	int		x;

	tmp = -1;
	len_b_to = 0;
	while (base_to[++tmp])
		len_b_to++;
	tmp = base_ten;
	len_string = 0;
	len_string = len_stringh(base_ten, len_string, len_b_to, neg);
	tab = (char *)ft_memalloc(sizeof(char) * len_string + 1);
	x = 0;
	tab[len_string] = '\0';
	while (base_ten != 0)
	{
		x = base_ten % len_b_to;
		tab[--len_string] = base_to[x];
		base_ten = base_ten / len_b_to;
	}
	neg && (tab[--len_string] = '-');
	return (tab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_ten;
	int		neg;
	char	*exep;

	if (nbr[0] == base_from[0])
	{
		exep = (char *)ft_memalloc(sizeof(char) * 2);
		exep[0] = base_to[0];
		exep[1] = '\0';
		return (exep);
	}
	neg = 0;
	if (nbr[0] == '-')
		neg++;
	base_ten = convert_b_ten(nbr, base_from, neg);
	return (convert_to_b(base_to, base_ten, neg));
}
