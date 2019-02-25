/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:03:24 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/25 08:40:53 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	has_split_room(t_list *path, int room, t_rooms *rooms)
{
	t_list	*i;
	int		c;

	i = path;
	while (i)
	{
		c = gfp((int *)i->content);
		if (rooms->paths[c][c] && c == room)
			return (1);
		i = i->next;
	}
	return (0);
}

static int	get_split_room(t_list *path, t_rooms *rooms)
{
	t_list	*i;
	int		current;
	int		room;

	i = path;
	room = -1;
	while (i)
	{
		current = gfp((int *)i->content);
		if (rooms->paths[current][current])
			room = current;
		i = i->next;
	}
	if (room == -1)
		room = current;
	return (room);
}

void		find_start_for_path(t_list **paths, t_list *path, int start,
			t_rooms *rooms)
{
	t_list	*i;
	t_list	*current;
	t_list	*best;
	t_list	*pl;
	int		split_room;

	i = *paths;
	pl = (t_list *)path->content;
	best = path;
	best->content_size = 0;
	split_room = get_split_room(pl, rooms);
	while (i)
	{
		current = (t_list *)i->content;
		if (i->content_size && current != pl && gfp((int *)current->content)
			== start && has_split_room(current, split_room, rooms))
		{
			i->content_size = 0;
			if (((t_list *)best->content)->content_size <
				((t_list *)current->content)->content_size)
				best = i;
		}
		i = i->next;
	}
	best->content_size = 1;
}

static int	has_room_in_path(t_list *current, int path_room)
{
	t_list	*i;

	i = current;
	while (i)
	{
		if (gfp((int *)i->content) == path_room)
			return (1);
		i = i->next;
	}
	return (0);
}

int			has_shared_room(t_list **paths, t_list *path, int start)
{
	t_list	*i;
	t_list	*current;
	int		path_room;

	i = *paths;
	path_room = gfp((int *)path->content);
	if (path_room == start)
		return (0);
	while (i)
	{
		current = (t_list *)i->content;
		if (i->content_size && current != path &&
			has_room_in_path(current, path_room))
			return (1);
		i = i->next;
	}
	return (0);
}
