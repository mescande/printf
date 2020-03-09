/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:27:49 by mescande          #+#    #+#             */
/*   Updated: 2020/02/26 13:34:54 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (len ? (char *)malloc(++len * sizeof(char)) : NULL);
	if (s2 == 0)
		return (s2);
	while (--len != 0)
		s2[len] = s1[len];
	s2[0] = s1[0];
	return (s2);
}
