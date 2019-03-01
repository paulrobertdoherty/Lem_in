/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:18:57 by pdoherty          #+#    #+#             */
/*   Updated: 2019/03/01 13:36:36 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				gfp(int *p)
{
	return (*p);
}

static void		visit(int visiting, t_rooms *rooms)
{
	rooms->paths[visiting][visiting] = rooms->paths[visiting][visiting] | 1;
}

static int		*get_room_pointers(t_rooms *rooms)
{
	int	*tr;
	int	i;

	tr = (int *)malloc(sizeof(int) * rooms->num_of_rooms);
	i = 0;
	while (i < rooms->num_of_rooms)
	{
		tr[i] = i;
		i++;
	}
	return (tr);
}

static t_list	*get_augmenting_path(t_rooms *rooms, int start, int end)
{
	t_list	*path;
	t_queue	*to_visit;
	int		*room_pointers;
	int		room;
	t_list	*connecting_rooms;

	to_visit = new_t_queue();
	push(to_visit, new_list(start));
	room_pointers = get_room_pointers(rooms);
	while (!is_empty(to_visit))
	{
		room = pop_to_visit(to_visit);
		connecting_rooms = get_connecting_rooms(room, rooms, end);
		while (connecting_rooms)
		{
			room_pointers[gfp((int *)connecting_rooms->content)] = room;
			visit(gfp((int *)connecting_rooms->content), rooms);
			push(to_visit, new_list(gfp((int *)connecting_rooms->content)));
			connecting_rooms = connecting_rooms->next;
		}
		ft_lstdel(&connecting_rooms, &delete_generic);
	}
	path = get_path(rooms, end, room_pointers);
	remove_visited(rooms, start);
	free(room_pointers);
	return (path);
}

t_list			*get_paths(t_rooms *rooms, int start, int end)
{
	t_queue	*paths;
	t_list	*paths_list;
	t_list	*ta;

	rooms->paths[start][start] = 1;
	paths = new_t_queue();
	while ((ta = get_augmenting_path(rooms, start, end)) != NULL)
		push(paths, ta);
	paths_list = peek(paths);
	free(paths);
	return (paths_list);
}
