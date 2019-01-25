/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:13:17 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/17 19:13:19 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tr;
	size_t	i;

	tr = (char *)malloc(sizeof(*tr) * (size + 1));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		tr[i] = '\0';
		i++;
	}
	return (tr);
}
