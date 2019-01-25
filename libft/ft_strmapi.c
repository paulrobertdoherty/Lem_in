/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:11:59 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 11:36:28 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tr;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	tr = ft_strnew(ft_strlen(s));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tr[i] = f(i, s[i]);
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
