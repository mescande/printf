/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:17:16 by mescande          #+#    #+#             */
/*   Updated: 2020/03/07 21:30:27 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	/*ft_printf("Voil%010c@\n", 'a');
	   printf("Voil%010c@\n", 'a');
	fflush(stdout);
	ft_printf("Voil%-010c@\n", 'a');
	   printf("Voil%-010c@\n", 'a');
	fflush(stdout);
	ft_printf("Voil%*c@\n", -10, 'a');
	   printf("Voil%*c@\n", -10, 'a');
	fflush(stdout);
	ft_printf("Voil%*c@patate\n", 10, 'a');
	   printf("Voil%*c@patate\n", 10, 'a');
	fflush(stdout);
	ft_printf("Voil%*c@%c\n", 10, 'a', 'B');
	   printf("Voil%*c@%c\n", 10, 'a', 'B');
	fflush(stdout);*/
/*	ft_printf("%*s@\n", 10, 0);
	   printf("%*s@\n", 10, 0);
	fflush(stdout);
	ft_printf("%*s@\n", 10, "patate");
	   printf("%*s@\n", 10, "patate");
	fflush(stdout);
	ft_printf("%-*s@\n", 10, "patate");
	   printf("%-*s@\n", 10, "patate");
	fflush(stdout);
	ft_printf("%.*s@\n", 10, "patate");
	   printf("%.*s@\n", 10, "patate");
	fflush(stdout);
	ft_printf("%-.*s@\n", 10, "patate");
	   printf("%-.*s@\n", 10, "patate");
	fflush(stdout);
	ft_printf("%*s@\n", -10, "patate");
	   printf("%*s@\n", -10, "patate");
	fflush(stdout);
	ft_printf("%-*s@\n", -10, "patate");
	   printf("%-*s@\n", -10, "patate");
	fflush(stdout);
	ft_printf("%.*s@\n", -10, "patate");
	   printf("%.*s@\n", -10, "patate");
	fflush(stdout);
	ft_printf("%-0*s@\n", 10, "patate");
	   printf("%-0*s$\n", 10, "patate");
	fflush(stdout);
	ft_printf("%0*s@\n", -10, "patate");
	   printf("%0*s$\n", -10, "patate");
	fflush(stdout);
	ft_printf("%*.*s@\n", 5, 1, 0);
	   printf("%*.*s$\n", 5, 1, 0);
	fflush(stdout);*/
/*	ft_printf("%d@\n", 42);
	   printf("%d$\n", 42);
	ft_printf("%8d@\n", 42);
	   printf("%8d$\n", 42);
	ft_printf("%30d@\n", 42);
	   printf("%30d$\n", 42);
	ft_printf("%-8d@\n", 42);
	   printf("%-8d$\n", 42);
	ft_printf("%0d@\n", 42);
	   printf("%0d$\n", 42);
	ft_printf("%2d@\n", 42);
	   printf("%2d$\n", 42);
	ft_printf("%2d@\n", 42000);
	   printf("%2d$\n", 42000);
	ft_printf("%.d@\n", 42);
	   printf("%.d$\n", 42);
	ft_printf("%.1d@\n", 42);
	   printf("%.1d$\n", 42);
	ft_printf("%.6d@\n", 42);
	   printf("%.6d$\n", 42);
	ft_printf("%8.123d@\n", 42);
	   printf("%8.123d$\n", 42);*/
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
/*	ft_printf("%*.*d%d%d%*s@\n", 8, -10, 42, 56, 3, 4, 0);
	   printf("%*.*d%d%d%*s$\n", 8, -10, 42, 56, 3, 4, 0);*/
/*	printf(" --- Return : %d\n", ft_printf("%0*.*u", 4, 2, 8)); //T21
	printf(" --- Return : %d\n",    printf("%0*.*u", 4, 2, 8)); //T21
	printf(" --- Return : %d\n", ft_printf("%0*.*x", 4, 2, 8)); //T21
	printf(" --- Return : %d\n",    printf("%0*.*x", 4, 2, 8)); //T21
*//*	printf(" --- Return : %d\n", ft_printf("%-0.0d %d", l, 12)); //T21
	printf(" --- Return : %d\n",    printf("%-0.0d %d", l, 12)); //T21
	printf(" --- Return : %d\n", ft_printf("%-.d", l)); //T17
	printf(" --- Return : %d\n",    printf("%-.d", l)); //T17
	a = 4;
	printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf(" --- Return : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
*/
	printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d\n",    printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	fflush(stdout);
/*	while (1);
		;
*/	return (0);
}
