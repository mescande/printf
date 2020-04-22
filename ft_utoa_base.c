/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:05:54 by mescande          #+#    #+#             */
/*   Updated: 2020/03/09 15:15:59 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_base(unsigned long long value, int big)
{
	char	*rep;
	char	buf[50];
	char	*ptr;

	ptr = &buf[49];
	rep = (big ? "0123456789ABCDEF" : "0123456789abcdef");
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ft_strdup(ptr));
}
