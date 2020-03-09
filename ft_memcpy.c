/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:37:42 by mescande          #+#    #+#             */
/*   Updated: 2020/02/24 19:28:22 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dsti;
	char	*srci;

	dsti = (char *)dst;
	srci = (char *)src;
	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	while (--n > 0)
		dsti[n] = srci[n];
	dsti[0] = srci[0];
	return (dst);
}
