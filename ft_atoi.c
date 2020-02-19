/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:15:09 by mescande          #+#    #+#             */
/*   Updated: 2020/01/28 12:08:53 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	long long	i;
	long long	j;
	long long	res;

	i = 0;
	j = 1;
	res = 0;
	if (*str == '*' || *str == '0' || *str == '.' ||
			(*str == '-' && *str + 1 == '*'))
		return (0);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			j = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (j == -1)
			res = res * 10 - (str[i++] - '0');
		else
			res = res * 10 + (str[i++] - '0');
	}
	return (res);
}
