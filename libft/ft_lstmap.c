/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:05:34 by pdoherty          #+#    #+#             */
/*   Updated: 2018/10/21 20:00:41 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tr;
	t_list	*i;
	t_list	*iter;

	if (lst == NULL)
		return (NULL);
	tr = f(lst);
	if (tr == NULL)
		return (NULL);
	i = tr;
	iter = lst->next;
	while (iter)
	{
		i->next = f(iter);
		if (tr->next == NULL)
			return (NULL);
		iter = iter->next;
		i = i->next;
	}
	return (tr);
}
