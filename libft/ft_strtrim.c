/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:14:28 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 16:41:07 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	set_start_and_end(int *st, int *e, int *c, int i)
{
	if (*st == -1)
		*st = i;
	*e = i;
	(*c)++;
}

static int	get_size(int *st, int *e)
{
	if (*st == -1 || *e == -1)
	{
		*st = 0;
		*e = -1;
		return (1);
	}
	return (1 + *e - *st);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' ||
			c == '\f');
}

char		*ft_strtrim(char const *s)
{
	int		st;
	int		e;
	int		i;
	int		c;
	char	*tr;

	i = -1;
	st = -1;
	e = -1;
	c = 0;
	while (s != NULL && s[++i])
	{
		if (!is_whitespace(s[i]))
			set_start_and_end(&st, &e, &c, i);
	}
	if (s == NULL || (st == -1 && c > 0))
		return ((char *)s);
	tr = (char *)malloc(sizeof(char) * get_size(&st, &e));
	if (tr == NULL)
		return (NULL);
	i = st - 1;
	while (++i <= e)
		tr[i - st] = s[i];
	tr[i - st] = '\0';
	return (tr);
}
