/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:17 by mescande          #+#    #+#             */
/*   Updated: 2020/04/20 12:34:59 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fillme(int *flag, char f, char *res)
{
	char	*tmp;
	int		var;
	int		i;
	int		len;

	tmp = res;
	i = 0;
	var = -1;
	len = ft_strlen(res);
	if (!(res = (char *)ft_memalloc(flag[wichflag(flag)] + 1)))
		return (NULL);
	if (f == '0' && tmp[0] == '-')
		res[(i++ == -2)] = (var++ == -2) + '-' + (len-- == -2);
	while (++var < flag[wichflag(flag)])
	{
		if (flag[MOINS])
			res[var] = (var < len ? tmp[var] : ' ');
		else
			res[var] = (var >= flag[wichflag(flag)] - len ? tmp[i++] : f);
	}
	free(tmp);
	res[var] = 0;
	return (res);
}

char	*conv_u(int *flag, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;

	var = (unsigned)va_arg(args, int);
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

char	*conv_x(int *flag, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;

	var = (unsigned)va_arg(args, int);
	if (!(res = ft_utoa_base(var, 0)))
		return (NULL);
	if (flag[VPREC] && flag[PRECI] == 0 && res[0] == '0' && !(flag[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flag[VPREC] && flag[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flag, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flag[VPREC] = 0;
	if (flag[wichflag(flag)] > (int)ft_strlen(res))
		res = fillme(flag, f, res);
	return (res);
}

char	*conv_bigx(int *flag, va_list args, char f)
{
	unsigned int	var;
	int				len;
	char			*res;

	var = (unsigned)va_arg(args, int);
	if (!(res = ft_utoa_base(var, 1)))
		return (NULL);
	if (flag[VPREC] && flag[PRECI] == 0 && res[0] == '0' && !(flag[VPREC] = 0))
		res = youdontwannadothis(res, ft_strnew(0));
	len = ft_strlen(res);
	if (flag[VPREC] && flag[PRECI] > (res[0] == '-' ? len - 1 : len))
		if (!(res = precision_in_conv_d(res, flag, len)))
			return (youdontwannadothis(res, NULL));
	len = ft_strlen(res);
	flag[VPREC] = 0;
	if (flag[wichflag(flag)] > (int)ft_strlen(res))
		res = fillme(flag, f, res);
	return (res);
}

char	*conv_pourcent(int *flag)
{
	char	c;
	char	*res;
	char	fil;
	int		len;
	int		i;

	c = '%';
	fil = (flag[ZEROS] ? '0' : ' ');
	len = flag[MOINS] + flag[ZEROS] + flag[PLUSS];
	i = 0;
	if (!(res = (char *)malloc(len)))
		return (NULL);
	if (flag[MOINS])
		res[i++] = c;
	while (i < len - 1)
		res[i++] = fil;
	res[i++] = (flag[MOINS] ? fil : c);
	res[(i > len && len != 0 ? len : i)] = 0;
	return (res);
}
