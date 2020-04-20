/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:26:48 by mescande          #+#    #+#             */
/*   Updated: 2020/03/07 20:42:21 by mescande         ###   ########.fr       */
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

t_list	**addstr(t_list **lst, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		*lst = addchar(*lst, str[i++]);
	if (!str)
		return (NULL);
	free(str);
	return (lst);
}

int		workonstr(const char *str, int i, va_list args, t_list **lst)
{
	int		j;
	int		flags[7];

	j = 1;
	initflags(flags);
	while (isflag(str[i + j]))
	{
		if (str[i + j] == '+')
			flags[PLUSS] = (j++ > 0);
		if (str[i + j] == '0' && !(flags[VPREC]) &&
				(isnum(str[i + j + 1]) ? 1 : ((j += 1) == 0)))
			flags[ZEROS] = (j++ > 0);
		if (str[i + j] == '-' && (isnum(str[i + j + 1]) ? 1 : ((j += 1) == 0)))
			flags[MOINS] = (j++ > 0);
		if (isnum(str[i + j]))
			flags[wichflag(flags)] = (str[i + j] != '*' ? atoi(str + i + j) :
					va_arg(args, int) + (j++ == 0));
		while (isnum(str[i + j]))
			j++;
		if (str[i + j] == '.')
			flags[VPREC] = (j++ > 0);
	}
	lst = addstr(lst, ft_putitin(flags, str[i + j], args, lst));
	return ((lst ? i + j + 1 : 0));
}

int		ft_printf(const char *str, ...)
{
	t_list	*lst;
	t_list	*start;
	int		i;
	va_list	args;

	if (!(lst = newelem()))
		return (0);
	start = lst;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			lst = addchar(lst, str[i++]);
		if (str[i])
		{
			if (!(i = workonstr(str, i, args, &lst)))
				return (0);
			if (lst->next)
				lst = lst->next;
		}
	}
	va_end(args);
	return (printit(start));
}
