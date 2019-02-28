/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:18:57 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/28 15:10:05 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				gfp(int *p)
{
	return (*p);
}

static void		visit(int visiting, int last, t_rooms *rooms,
				int *room_pointers)
{
	room_pointers[visiting] = last;
	rooms->paths[visiting][visiting] = 1;
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
		room = gfp((int *)pop(to_visit));
		connecting_rooms = get_connecting_rooms(room, rooms);
		while (connecting_rooms)
		{
			visit(gfp((int *)connecting_rooms->content), room, rooms,
					room_pointers);
			push(to_visit, new_list(gfp((int *)connecting_rooms->content)));
			connecting_rooms = connecting_rooms->next;
		}
		ft_lstdel(&connecting_rooms, &delete_generic);
	}
	path = get_path(rooms, end, room_pointers);
	free(room_pointers);
	return (path);
}

t_list			*get_paths(t_rooms *rooms, int start, int end)
{
	t_queue	*paths;
	t_list	*paths_list;
	t_list	*ta;

	paths = new_t_queue();
	while ((ta = get_augmenting_path(rooms, start, end)) != NULL)
		push(paths, ta);
	paths_list = peek(paths);
	free(paths);
	return (paths_list);
}
