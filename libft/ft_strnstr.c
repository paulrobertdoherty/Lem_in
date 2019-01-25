/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:13:35 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/19 20:28:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	r1(size_t *j, int *in)
{
	*j = -1;
	*in = 0;
}

static void	init(size_t *i, size_t *j, int *is_not)
{
	*i = -1;
	*j = 0;
	*is_not = 0;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		is_not;
	size_t	i;
	size_t	j;
	size_t	nl;

	nl = ft_strlen(needle);
	if (nl == 0)
		return ((char *)haystack);
	init(&i, &j, &is_not);
	while (haystack[++i] && i < len)
	{
		r1(&j, &is_not);
		while (needle[++j] && i + j < len)
		{
			if (haystack[j + i] != needle[j])
			{
				is_not = 1;
				break ;
			}
		}
		if (j > 0 && is_not == 0 && needle[j] == '\0')
			return ((char *)(&haystack[i]));
	}
	return (NULL);
}
