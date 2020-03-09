/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestionflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:42 by mescande          #+#    #+#             */
/*   Updated: 2020/03/07 18:32:32 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initflags(int *flags)
{
	int i;

	i = 0;
	while (i < 7)
		flags[i++] = 0;
	return ;
}

int		*verifflags(int *flags)
{
	if (flags[ZEROS] < 0)
	{
		flags[MOINS] = -flags[ZEROS];
		flags[ZEROS] = 0;
	}
	if (flags[ZEROS] == 1 && flags[PLUSS])
	{
		flags[ZEROS] = flags[PLUSS];
		flags[PLUSS] = 0;
	}
	if (flags[PLUSS] < 0)
	{
		flags[MOINS] = -flags[PLUSS];
		flags[PLUSS] = 0;
	}
	if (flags[PRECI] < 0)
		flags[VPREC] = 0;
	if (flags[VPREC] && flags[ZEROS])
	{
		flags[PLUSS] = flags[ZEROS];
		flags[ZEROS] = 0;
	}
	if (flags[MOINS] < 0)
		flags[MOINS] = -flags[MOINS];
	return (flags);
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
//	printf("FLAGS : %d, %d, %d, %d, %d\n", flags[0], flags[PLUSS], flags[MOINS], flags[PRECI], flags[VPREC]);
	if (flags[VPREC])
		return (PRECI);
	if (flags[MOINS])
	{
		flags[ZEROS] = 0;
		return (MOINS);
	}
	if (flags[ZEROS])
		return (ZEROS);
	return (PLUSS);
}
