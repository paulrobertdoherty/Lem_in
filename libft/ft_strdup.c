/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:47:53 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/25 16:49:51 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tr;
	size_t	i;

	tr = (char *)malloc((1 + ft_strlen(str)) * sizeof(char));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tr[i] = str[i];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
