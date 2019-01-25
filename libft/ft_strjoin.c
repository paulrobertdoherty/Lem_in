/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:11:12 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 11:39:19 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tr;
	size_t	i;
	size_t	l;
	size_t	s1l;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	l = s1l + ft_strlen(s2);
	tr = ft_strnew(l);
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		if (i < s1l)
			tr[i] = s1[i];
		else
			tr[i] = s2[i - s1l];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
