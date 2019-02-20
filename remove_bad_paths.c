/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_bad_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:36:23 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/19 20:22:57 by pdoherty         ###   ########.fr       */
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
size_t			num_of_shared_rooms(t_list *current, t_list **paths, int *sae)
{
	size_t	rooms;
	t_list	*j;
	t_list	*c;
	int		cu;

	rooms = 0;
	cu = gfp((int *)current->content);
	j = (cu != sae[0] && cu != sae[1]) ? *paths : NULL;
	while (j)
	{
		c = (t_list *)j->content;
		if (c != current)
			rooms += count_in_path(c, cu);
		j = j->next;
	}
	return (rooms);
}

t_list			*move_to_next(t_list *current, int is_at_end, int end_paths)
{
	t_list	*i;
	t_list	*last;
	int		j;

	last = current;
	i = current->next;
	j = 0;
	while (i)
	{
		if ((is_at_end && j == end_paths) ||
			last->content_size < i->content_size)
			return (last);
		last = i;
		i = i->next;
		j++;
	}
	return (last);
}
