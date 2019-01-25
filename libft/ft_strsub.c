/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:14:18 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 14:18:12 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	tr = ft_strnew(len);
	if (tr == NULL)
		return (NULL);
	i = (size_t)start;
	while (s[i] && i - start < len)
	{
		tr[i - start] = s[i];
		i++;
	}
	tr[i - start] = '\0';
	return (tr);
}
