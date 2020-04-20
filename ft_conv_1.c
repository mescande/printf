/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:17 by mescande          #+#    #+#             */
/*   Updated: 2020/04/20 12:31:30 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_c(int *flags, va_list args, t_list **lst)
{
	char	c;
	char	*res;
	char	fil;
	int		len;
	int		i;

	c = va_arg(args, int);
	fil = (flags[ZEROS] ? '0' : ' ');
	len = flags[MOINS] + flags[ZEROS] + flags[PLUSS];
	i = 0;
	if (!(res = (char *)malloc(len)))
		return (NULL);
	if (flags[MOINS])
		res[i++] = c;
	while (i < len - 1)
		res[i++] = fil;
	res[i++] = (flags[MOINS] ? fil : c);
	res[(i > len ? len : i)] = 0;
	if (c == 0 && !(i = 0))
	{
		while (i < len || i == 0)
			*lst = addchar(*lst, res[i++]);
		res[0] = 0;
	}
	return (res);
}

char	*conv_s(int *flags, va_list args, int k)
{
	char	*res;
	char	*var;
	int		min;
	char	fil;
	int		i;

	if (!(var = ft_strdup(va_arg(args, char *))))
		var = ft_strdup("(null)");
	min = flags[MOINS] + flags[ZEROS] + flags[PLUSS];
	i = precision_in_conv_s(0, flags, var);
	fil = (flags[ZEROS] ? '0' : ' ');
	if (!(res = (char *)malloc((i < min ? min : i) + 1)))
		return (youdontwannadothis(var, NULL));
	while (k < (i < min ? min : i))
	{
		if ((k < i * flags[MOINS] && k < i) || (k >= (int)(min - i) && *var))
			res[k++] = *(var++);
		else
			res[k++] = fil;
	}
	res[k] = 0;
	return (youdontwannadothis(var - i, res));
}

char	*conv_p(int *flags, va_list args)
{
	unsigned long long	val;
	char				*res;

	(void)flags;
	val = (unsigned long long)va_arg(args, void *);
	if (!(res = ft_utoa_base(val, 0)))
		return (NULL);
	if (!(res = ft_strjoin("0x", res)))
		return (NULL);
	if (flags[wichflag(flags)] > (int)ft_strlen(res))
		res = fillme(flags, (flags[ZEROS] ? '0' : ' '), res);
	return (res);
}

char	*conv_d(int *flag, va_list args, char f)
{
	int		var;
	int		len;
	char	*res;

	var = va_arg(args, int);
	if (!(res = ft_itoa(var)))
		return (NULL);
	if (flag[VPREC] && flag[PRECI] == 0 && res[0] == '0' && !(flag[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flag[VPREC] && flag[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flag, len)))
			return (youdontwannadothis(res, NULL));
	flag[VPREC] = 0;
	if (flag[wichflag(flag)] > (int)ft_strlen(res))
		res = fillme(flag, f, res);
	return (res);
}
