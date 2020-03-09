/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:01:40 by mescande          #+#    #+#             */
/*   Updated: 2020/03/09 14:14:42 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(long int n)
{
	char		*res;
	size_t		len;
	long int	tmp;
	int			neg;

	tmp = n;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	len = (n < 0 ? 1 : 0);
	while (tmp != 0 && ++len)
		tmp /= 10;
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	tmp = n;
	neg = (n < 0 ? -1 : 1);
	while (tmp != 0)
	{
		res[--len] = '0' + neg * (tmp % 10);
		tmp /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
