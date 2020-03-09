/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:17 by mescande          #+#    #+#             */
/*   Updated: 2020/03/09 15:19:00 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conv_u(int *flags, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;
	char			*tmp;
	int				i;

	var = (unsigned)va_arg(args, int);
	if (!(res = ft_itoa(var)))
		return (NULL);
	i = 0;
	if (flags[VPREC] && flags[PRECI] == 0 && res[0] == '0' && !(flags[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flags[VPREC] && flags[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flags, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flags[VPREC] = 0;
	if (flags[((var = -1) == 0) + wichflag(flags)] > (int)ft_strlen(res))
	{
		tmp = res;
		if (!(res = (char *)malloc(flags[wichflag(flags)])))
			return (NULL);
		(f == '0' && tmp[0] ==  '-' ? res[var++ + 1] = '-' + (i++ == -2) +
		 (len-- == 0) : var);
		while (++var < flags[wichflag(flags)])
		{
			if (flags[MOINS])
				res[var] = (var < len ? tmp[var] : ' ');
			else
				res[var] = (var >= flags[wichflag(flags)] - len ? tmp[i++] : f);
		}
		free(tmp);
	}
	return (res);
}

char	*conv_x(int *flags, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;
	char			*tmp;
	int				i;

	var = (unsigned)va_arg(args, int);
	if (!(res = ft_utoa_base(var, 0)))
		return (NULL);
	i = 0;
	if (flags[VPREC] && flags[PRECI] == 0 && res[0] == '0' && !(flags[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flags[VPREC] && flags[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flags, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flags[VPREC] = 0;
	if (flags[((var = -1) == 0) + wichflag(flags)] > (int)ft_strlen(res))
	{
		tmp = res;
		if (!(res = (char *)malloc(flags[wichflag(flags)])))
			return (NULL);
		(f == '0' && tmp[0] ==  '-' ? res[var++ + 1] = '-' + (i++ == -2) +
		 (len-- == 0) : var);
		while (++var < flags[wichflag(flags)])
		{
			if (flags[MOINS])
				res[var] = (var < len ? tmp[var] : ' ');
			else
				res[var] = (var >= flags[wichflag(flags)] - len ? tmp[i++] : f);
		}
		free(tmp);
	}
	return (res);
}

char	*conv_bigx(int *flags, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;
	char			*tmp;
	int				i;

	var = (unsigned)va_arg(args, int);
	if (!(res = ft_utoa_base(var, 1)))
		return (NULL);
	i = 0;
	if (flags[VPREC] && flags[PRECI] == 0 && res[0] == '0' && !(flags[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flags[VPREC] && flags[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flags, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flags[VPREC] = 0;
	if (flags[((var = -1) == 0) + wichflag(flags)] > (int)ft_strlen(res))
	{
		tmp = res;
		if (!(res = (char *)malloc(flags[wichflag(flags)])))
			return (NULL);
		(f == '0' && tmp[0] ==  '-' ? res[var++ + 1] = '-' + (i++ == -2) +
		 (len-- == 0) : var);
		while (++var < flags[wichflag(flags)])
		{
			if (flags[MOINS])
				res[var] = (var < len ? tmp[var] : ' ');
			else
				res[var] = (var >= flags[wichflag(flags)] - len ? tmp[i++] : f);
		}
		free(tmp);
	}
	return (res);
}

char	*conv_pourcent(int *flags, va_list args)
{
	char	c;
	char	*res;
	char	fil;
	int		len;
	int		i;

	c = '%';
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
