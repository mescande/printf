/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestionflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:42 by mescande          #+#    #+#             */
/*   Updated: 2020/02/19 11:45:02 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initflags(int *flags)
{
	int i;

	i = 0;
	while (i < 6)
		flags[i++] = 0;
	return ;
}

int		isflag(char c)
{
	if (c == '0' || c == '-' || c == '+' || c == '*' || c == '.' ||
			(47 < c && c < 58))
		return (1);
	return (0);
}

int		wichflag(int *flags)
{
	if (flags[PRECI] == 1)
	{
		flags[ZEROS] = 0;
		return (PRECI);
	}
	if (flags[MOINS])
	{
		flags[ZEROS] = 0;
		return (MOINS);
	}
	if (flags[ZEROS])
		return (ZEROS);
	return (PLUSS);
}
