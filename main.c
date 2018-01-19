/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:32:27 by smortier          #+#    #+#             */
/*   Updated: 2017/11/30 16:32:31 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

//#define  __TEST__ "toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0
//#define  __TEST__ "%.0U", 0
//#define  __TEST__ "\ntoto et %00009U || %-2lu mimi et titi%--14u", 0, (unsigned long)14, 200

//#define  __TEST__ "%1o", 0
//#define  __TEST__ "t%04.2o%#2oet %#-8.3o titi", 0, 0, 0
//#define  __TEST__ "\n%024hho et%#1.2o '%0012.O'", (unsigned char)12, 0, 123654789
//#define  __TEST__ "test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499

//#define  __TEST__ "t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1
//#define  __TEST__ "toto '%0##0.4X''%#4.2x'et c'est fini \n", 0x037a, 0x9e
//#define  __TEST__ "cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0
//#define  __TEST__ "%#.22zX et %020.14jx", 0xff1144ff1144, 0xffaabbccee

///Conv c
//#define  __TEST__ "hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0 //curqui dit non alors que ca marche ??

///CONV C
//#define  __TEST__ "%C", 0x11ffff
//#define  __TEST__ "%C", (wint_t)-2
//#define  __TEST__ "%C", 0xd800
//#define  __TEST__ "%C", 0xdb02
//#define  __TEST__ "%C", 0xdfff
//#define  __TEST__ "%C", 0xbffe
//#define  __TEST__ "%lc", 254
//#define  __TEST__ "%C", 256
//#define  __TEST__ "%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'
//#define  __TEST__ "%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'
//#define  __TEST__ "yo'%2C'%-12lc' et '%C' titi '%C' tyty", 'u', 254, 256, 'a'
//#define __TEST__ "%C", 0xdfff

///Conv s
//#define  __TEST__ "%.2s", NULL //pas 2 char de (null) > (n
//#define  __TEST__ "%10s", NULL //pas 10 de lenght
//#define  __TEST__ "Coucou %.0s\n%s'%---12s'", "hi", "coco", NULL //mettre null a gauche puis des espace pour lenght 12
//#define  __TEST__ "u '%4.2s' s, '%-1.s'  '%---5.3s' ", "coco", NULL, "yooo" // 4.2 marche pas et met un null avec un prec de 0
//#define  __TEST__ "%--12s // %--12s", NULL, "(yolo)"


///pourcent
//#define  __TEST__ "%#%"
//#define  __TEST__ "%.0%"
//#define  __TEST__ "%.%"
//#define  __TEST__ "%017%" //abort ?? fsanitize
//#define  __TEST__ "titi % +---12.5% et%%%0004% et %+1%"

///FC ERROR
//#define  __TEST__ "%10R" //fc qui pete un cable encore
//#define  __TEST__ "%5.o %5.0o", 0, 0
//#define  __TEST__ "%5.x %5.0x", 0, 0
//#define  __TEST__ "%5.d %5.0d", 0, 0
//#define  __TEST__ "%zd", (size_t)-1 // comment un size_t peut etre neg ?????
//#define  __TEST__ "%hhC, %hhC", 0, L'Á±≥'
//#define  __TEST__ "{%S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B" //lenght_min avec S on met quand meme toute la chaine


///Mixed error
#define  __TEST__ "test %-12i et '%--2.4s' '%24s' !", 0, NULL, "cooc"
//#define  __TEST__ "%--.4u et %#O%#012O%1lc", -12, 0, 0, 95
//#define  __TEST__ "test %-7C %007d'%-10.2ls'!!", 0xd777, 0x45, L"〻" // je fait le bon truc non ?

int		main(void)
{

	setlocale(LC_ALL, "");
	int ret = 0;
	ret = ft_printf(__TEST__);
	printf("\nReturn [ft_printf] > {%d}\n",ret);
	ret = printf(__TEST__);
	printf("\nReturn [printf] > {%d}\n",ret);
	return (0);
}
