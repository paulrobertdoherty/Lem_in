/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:47:32 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/23 14:09:43 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*memory;
	size_t			i;

	memory = (unsigned char *)ptr;
	i = 0;
	while (i < n)
		memory[i++] = (unsigned char)x;
	return ((void *)ptr);
}
