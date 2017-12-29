/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:30:11 by smortier          #+#    #+#             */
/*   Updated: 2017/11/30 16:30:12 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


t_conv		*ft_newconv(char *str, char c)
{
	t_conv		*newconv;

	if (!(newconv = (t_conv *)ft_memalloc(sizeof(t_conv))))
		return (NULL);
	newconv->first_arg = str;
	newconv->final_arg = NULL;
	newconv->type_letter = c;
	newconv->specifier = NULL;
	newconv->type = NULL;
	newconv->precision = 0;
	newconv->next = NULL;
	newconv->prev = NULL;
	return (newconv);
}

t_conv		*ft_create_lst(t_conv *conv, char *str, char c)
{
	t_conv *temp;

	if (conv == NULL)
		return(ft_newconv(str, c));
	else
	{
		temp = conv;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_newconv(str, c);
		temp->next->prev = temp;
		return (conv);
	}
}
/////////////////////////STOOP LA//////////////////////////////
t_conv		*ft_fill_lst(t_conv *t_conv, char * format)
{
	unsigned int	index;
	unsigned int	index_prc;

	index = 0;
	while (format[index] && index < ft_strlen(format))
	{
		index_prc = 0;
		if (format[index] == '%')
		{
			index++;
			while (format[index + index_prc] &&
					!ft_spot_converter(format[index + index_prc]))
				index_prc++;
			t_conv = ft_create_lst(t_conv,
								   ft_strsub(format, index, index_prc),
								   format[index + index_prc]);
			index += index_prc + 1;
		}
		else
		{
			while (format[index + index_prc] &&
					format[index + index_prc] != '%')
				index_prc++;
			t_conv = ft_create_lst(t_conv,
								   ft_strsub(format, index, index_prc), 0);
			index += index_prc;
		}
	}
	return (t_conv);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		arg;
	t_conv		*conv;
	int			ret;

	conv = NULL;
	conv = ft_fill_lst(conv, (char *)format); //Lst bien remplit
	/*******************DEBUG LST****************************/
	/*while (conv->next)
	{
		ft_putstr(conv->first_arg);
		ft_putstr("|  type = ");
		ft_putchar(conv->type_letter);
		ft_putchar('\n');
		conv = conv->next;
	}*/

	/*****************FIN DEBUG LST**************************/
	// ici on peut transformer tous les
	// O S p etc p = #lx par exemple si on les vois on change
	/********************FORMATION STR***********************/
	ft_formate_str(conv);

	/*****************FIN FORMATION STR**********************/

	/********************GET SPECIFIER************************/
	ft_get_specifier(conv);
	/*while (conv)
	{
		printf("specifier = [%s]\n", conv->specifier);
		printf("precision = [%d]\n", (int)conv->precision);
		printf("lenght_min = [%d]\n", (int)conv->lenght_min);
		conv = conv->next;
	}*/
	/*****************FIN GET SPECIFIER***********************/


	/*****************TYPING*****************/
	va_start(arg, format);
	ft_typing(conv, arg);
	va_end(arg);
	/*while (conv)
	{
	 	if (conv->type_letter)
			ft_putnbr((int)conv->type);
		ft_putchar('\n');
		conv = conv->next;
	}*/
	/*************FIN TYPING****************/

	ft_typing_to_str(conv);
	/*while (conv)
	{
		if (conv->type_letter)
			ft_putstr(conv->typing);
		else
			ft_putstr(conv->first_arg);
		conv = conv->next;
	}*/
	// JE PENSE QUE TOUT EST BON JUSKE LA

	/*****************ATTRIBUTING*****************/
	ft_parse_attribute(conv);
	/***************FIN ATTRIBUTING***************/

	ft_attribute_zero(conv);
	ft_attribute_less(conv);
	ft_hold_precision_zero(conv);
	/***************DEBUG ATTRIBUTING*************/
	ret = 0;
	int		i;
	while (conv)
	{
		if (conv->final_arg == NULL && conv->type_letter == 's')
		{
			ft_putstr("(null)");
			ret += ft_strlen("(null)");
		}
		else if (conv->type_letter == 'c' && !(char)conv->type)
		{
			i = -1;
			if (!ft_strchr(conv->first_arg, '.'))
			{
				while (++i < (int)ft_strlen(conv->final_arg) - 1)
					(ft_strchr(conv->first_arg, '0') ? ft_putchar('0') : ft_putchar(' '));
			}
			ft_putchar(conv->final_arg[ft_strlen(conv->final_arg)]);
			ret += (conv->lenght_min) ? (int)ft_strlen(conv->final_arg) :
				  1;
		}
		else
		{
			ft_putstr(conv->final_arg);
			ret += (int)ft_strlen(conv->final_arg);
		}
		conv = conv->next;
	}
	//GOOD POUR #, ' ', + et on va dire que c'est bon pour toutes les conversions
	/*************FIN DEBUG ATTRIBUTING************/


	return (ret);
}