/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:17 by mescande          #+#    #+#             */
/*   Updated: 2020/03/09 13:25:57 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_c(int *flags, va_list args)
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
	res[i] = 0;
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
	return (NULL);
}

char	*conv_d(int *flag, va_list args, char f)
{
	int		var;
	int		len;
	char	*res;
	char	*tmp;
	int		i;

	var = va_arg(args, int);
	if (!(res = ft_itoa(var)))
		return (NULL);
	i = 0;
	if (flag[VPREC] && flag[PRECI] == 0 && res[0] == '0' && !(flag[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flag[VPREC] && flag[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flag, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flag[VPREC] = 0;
	if (flag[((var = -1) == 0) + wichflag(flag)] > (int)ft_strlen(res))
	{
		tmp = res;
		if (!(res = (char *)malloc(flag[wichflag(flag)])))
			return (NULL);
		(f == '0' && tmp[0] ==  '-' ? res[var++ + 1] = '-' + (i++ == -2) +
		 (len-- == 0) : var);
		while (++var < flag[wichflag(flag)])
		{
			if (flag[MOINS])
				res[var] = (var < len ? tmp[var] : ' ');
			else
				res[var] = (var >= flag[wichflag(flag)] - len ? tmp[i++] : f);
		}
		free(tmp);
	}
	return (res);
}
