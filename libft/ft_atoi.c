/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:23:58 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/21 15:16:03 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
			c == '\f');
}

int			ft_atoi(char *str)
{
	int tr;
	int i;
	int	s;

	tr = 0;
	s = 0;
	while (is_whitespace(str[s]) && str[s] != '-' && str[s] != '+')
		s++;
	i = s;
	if (str[s] == '-' || str[s] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			tr = (tr * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	if (str[s] == '-')
		tr *= -1;
	return (tr);
}
