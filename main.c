/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:17:16 by mescande          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:29 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_printf("Voil%30c\n", 'a');
	printf("Voil%30.10d\n", 'a');
	ft_printf("Voil%30c\n", 'a');
	printf("Voil%-30.10d\n", 'a');
	ft_printf("Voil%30c\n", 'a');
	printf("Voil%30c\n", 'a');
	return (0);
}
