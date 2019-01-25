/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:12:16 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/17 19:12:18 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	l = (size_t)ft_strlen(s1);
	i = l;
	while (i - l < n)
	{
		if (s2[i - l])
			s1[i] = s2[i - l];
		else
			break ;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
