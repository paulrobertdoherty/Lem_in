/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:11:47 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 11:35:26 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tr;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	tr = ft_strdup((char *)s);
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tr[i] = f(s[i]);
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
