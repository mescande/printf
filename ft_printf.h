/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:17:15 by mescande          #+#    #+#             */
/*   Updated: 2020/02/19 14:35:36 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 999

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

/*
**flags[6] = {ZEROS, PLUS, MOINS, DIESE, PRECI, 0}
**conv :	c=99	s=115	p=112	d=100	i=105	u=117	x=120	X=88	%=37
**			n=110	f=102	g=103	e=101
*/

enum			e_flags
{
	ZEROS,
	PLUSS,
	MOINS,
	DIESE,
	PRECI,
};

typedef struct	s_list
{
	char			*str;
	int				len;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);

char			*ft_putitin(int *flags, const char *str, int i, t_list *lst);

void			initflags(int *flags);
int				isflag(char c);
int				wichflag(int *flags);

t_list			*newelem(void);
t_list			*addchar(t_list *lst, char c);
t_list			*addstr(t_list *lst, char *str);
int				workonstr(const char *str, int i, va_list args, t_list *lst);
int				ft_printf(const char *str, ...);

#endif
