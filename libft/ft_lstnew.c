/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:05:50 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/22 21:07:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (content == NULL)
			list->content_size = 0;
		else
		{
			list->content = ft_memcpy(ft_memalloc(content_size),
					content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
