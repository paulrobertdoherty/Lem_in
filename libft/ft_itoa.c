/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:04:00 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/21 14:48:23 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ctn(char *tr, int *n)
{
	if (*n < 0)
	{
		tr[0] = '-';
		*n *= -1;
	}
}

static void	fun(int *n, int *i)
{
	*n /= 10;
	(*i)++;
}

char		*ft_itoa(int n)
{
	char	*tr;
	int		digits;
	int		length;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	digits = ft_digits(n);
	length = digits;
	if (n < 0)
		length++;
	tr = (char *)malloc(sizeof(char) * (length + 1));
	if (tr == NULL)
		return (NULL);
	ctn(tr, &n);
	i = 0;
	while (i < digits)
	{
		tr[-1 + length - i] = (n % 10) + '0';
		fun(&n, &i);
	}
	tr[length] = '\0';
	return (tr);
}
