/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putitin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:57:50 by mescande          #+#    #+#             */
/*   Updated: 2020/03/09 15:18:25 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*youdontwannadothis(char *tofree, char *ret)
{
	free(tofree);
	return (ret);
}

int		isnum(char c)
{
	return (((c == '*') || ('0' <= c && c <= '9')));
}

int		precision_in_conv_s(int i, int *flags, char *var)
{
	i = (flags[VPREC] ? 0 : ft_strlen(var));
	while (flags[VPREC] && var[i])
	{
		if (i >= flags[PRECI])
			var[i] = 0;
		else
			i++;
	}
	return (i);
}

char	*precision_in_conv_d(char *res, int *flags, int len)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = res;
	i = 0;
	j = 0;
	if (!(res = (char *)malloc(flags[PRECI] + (tmp[0] == '-' ? 1 : 0))))
		return (NULL);
	if (tmp[0] == '-')
	{
		res[i] = '-' + (j++ == -1);
		len--;
		flags[PRECI]++;
	}
	else
		res[i] = '0';
	while (++i <= flags[PRECI])
		res[i] = (i >= flags[PRECI] - len ? tmp[j++] : '0');
	free(tmp);
	flags[PRECI] = 0;
	flags[VPREC] = 0;
	return (res);
}

char	*ft_putitin(int *flags, char c, va_list args)
{
	flags = verifflags(flags);
	if (c == 'c')
		return (conv_c(flags, args));
	if (c == 's')
		return (conv_s(flags, args, 0));
	if (c == 'p')
		return (conv_p(flags, args));
	if (c == 'd' || c == 'i')
		return (conv_d(flags, args, (flags[ZEROS] ? '0' : ' ')));
//	write(1, &c, 1);
//	write(1, "\n", 1);
	if (c == 'u')
		return (conv_u(flags, args, (flags[ZEROS] ? '0' : ' ')));
	if (c == 'x')
		return (conv_x(flags, args, (flags[ZEROS] ? '0' : ' ')));
	if (c == 'X')
		return (conv_bigx(flags, args, (flags[ZEROS] ? '0' : ' ')));
	if (c == '%')
		return (conv_pourcent(flags, args));
	return (NULL);
}
