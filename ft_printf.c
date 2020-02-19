/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:26:48 by mescande          #+#    #+#             */
/*   Updated: 2020/02/19 14:33:15 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*newelem(void)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!(res->str = (char *)malloc(BUFFER_SIZE + 1)))
		return (0);
	res->len = 0;
	res->next = NULL;
	res->str[BUFFER_SIZE] = 0;
	return (res);
}

t_list	*addchar(t_list *lst, char c)
{
	if (lst->len == BUFFER_SIZE)
	{
		lst->next = newelem();
		lst = lst->next;
	}
	lst->str[lst->len++] = c;
	return (lst);
}

t_list	*addstr(t_list *lst, char *str)
{
	while (*str)
		lst = addchar(lst, *(str++));
	return (lst);
}

int		workonstr(const char *str, int i, va_list args, t_list *lst)
{
	int		j;
	int		len;
	int		flags[6];

	j = 1;
	len = 1;
	initflags(flags);
	while (isflag(str[i + j]))
	{
		if (str[i + j] == '0')
			flags[ZEROS] = (j++ > 0);
		if (str[i + j] == '-')
			flags[MOINS] = (j++ > 0);
		if (str[i + j] == '+')
			flags[PLUSS] = (j++ > 0);
		if (str[i + j] == '*' || (47 < str[i + j] && str[i + j] < 58))
		{
			flags[wichflag(flags)] = (str[i + j] == '*' ? va_arg(args, int) :
					atoi(str + i + j));
			while (47 < str[i + j + 1] && str[i + j + 1] < 58)
				j++;
		}
		if (str[i + j] == '.')
			flags[PRECI] = 1;
		j++;
	}
	lst = addstr(lst, ft_putitin(flags, str, i + j, lst));
	return (i + j + 1);
}

int		ft_printf(const char *str, ...)
{
	t_list	*lst;
	t_list	*start;
	int		i;
	va_list	args;

	lst = newelem();
	start = lst;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			lst = addchar(lst, str[i++]);
		if (str[i])
		{
			i = workonstr(str, i, args, lst);
			if (!lst->next)
				lst->next = newelem();
			lst = lst->next;
		}
	}
/*	join;
	write;*/
	while (start)
	{
		write(1, start->str, start->len);
		start = start->next;
	}
	va_end(args);
	return (0);
}
