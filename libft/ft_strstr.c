/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:14:08 by pdoherty          #+#    #+#             */
/*   Updated: 2018/09/17 19:14:10 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int is_not;
	int i;
	int j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	j = 0;
	is_not = 0;
	while (haystack[++i])
	{
		j = -1;
		is_not = 0;
		while (needle[++j])
		{
			if (haystack[j + i] != needle[j])
			{
				is_not = 1;
				break ;
			}
		}
		if (is_not == 0)
			return ((char *)(&haystack[i]));
	}
	return (NULL);
}
