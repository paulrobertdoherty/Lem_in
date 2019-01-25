/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_of_splits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:37:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/14 10:15:25 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_of_splits(char const *s, char c)
{
	int	i;
	int	num;
	int	in;

	i = 0;
	num = 0;
	in = 1;
	while (s[i])
	{
		if (s[i] == c)
			in = 1;
		if (s[i] != c)
		{
			if (in)
				num++;
			in = 0;
		}
		i++;
	}
	return (num);
}
