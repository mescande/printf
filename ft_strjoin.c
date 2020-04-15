/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:25:56 by mescande          #+#    #+#             */
/*   Updated: 2019/04/25 00:29:27 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	l;

	l = 0;
	while (src[l] != '\0')
	{
		dst[l] = src[l];
		l++;
	}
	dst[l] = '\0';
	return (dst);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = -1;
	while (s1[i] != '\0')
		i++;
	while (s2[++j] != '\0')
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}

char		*ft_strjoin(const char *s1, char *s2)
{
	char *res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
	if (res == NULL)
		return (NULL);
	res = ft_strcat(ft_strcpy(res, s1), s2);
	free(s2);
	return (res);
}
