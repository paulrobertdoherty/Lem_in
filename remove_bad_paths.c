/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_bad_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:36:23 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/11 13:55:21 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	count_in_path(t_list *path, int room)
{
	t_list	*i;

	i = path;
	while (i)
	{
		if (gfp((int *)i->content) == room)
			return (1);
		i = i->next;
	}
	return (0);
}

//TODO: Improve with dynamic programming
size_t			num_of_shared_rooms(t_list *current, t_list **paths, int end)
{
	size_t	rooms;
	t_list	*i;
	t_list	*j;
	t_list	*c;
	int		cu;

	rooms = 0;
	i = current;
	while (i)
	{
		cu = gfp((int *)i->content);
		j = (cu != end) ? *paths : NULL;
		while (j)
		{
			c = (t_list *)j->content;
			if (c != i)
				rooms += count_in_path(c, cu);
			j = j->next;
		}
		i = i->next;
	}
	return (rooms);
}

t_list			*get_last_path(t_list **paths, int end_paths)
{
	t_list	*i;
	int		j;

	i = *paths;
	j = 0;
	while (i)
	{
		if (j == end_paths - 1)
			return (i);
		j++;
		i = i->next;
	}
	return (i);
}

t_list			*move_to_next(t_list *current)
{
	t_list	*i;
	t_list	*last;

	last = current;
	i = current->next;
	while (i)
	{
		if (last->content_size < i->content_size)
			return (i);
		last = i;
		i = i->next;
	}
	return (i);
}
