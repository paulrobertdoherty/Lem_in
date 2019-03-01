/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_long_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:40:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/28 19:36:51 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_long_paths(t_list **paths, int ants)
{
	t_list	*i;
	t_list	*last;
	size_t	c;

	last = *paths;
	i = last->next;
	c = 2;
	while (i)
	{
		if (i->content_size * c > (size_t)ants)
			break ;
		c++;
		last = i;
		i = i->next;
	}
	last->next = NULL;
	ft_lstdel(&i, &delete_paths);
}
