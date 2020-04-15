/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:34:57 by mescande          #+#    #+#             */
/*   Updated: 2019/04/09 20:33:51 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	char	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	while (--size != 0)
		res[size] = 0;
	res[0] = 0;
	return ((void *)res);
}
