/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:50:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/25 07:31:13 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*new_list(int n)
{
	t_list	*tr;
	int		*ta;

	ta = (int *)malloc(sizeof(int));
	*ta = n;
	tr = (t_list *)malloc(sizeof(t_list));
	tr->content = ta;
	tr->content_size = 1;
	tr->next = NULL;
	return (tr);
}

/*
**An easy way to get an int from an int pointer. It's for aesthetics
*/

int			gfp(int *p)
{
	return (*p);
}

static int	can_continue(t_list *paths, int start, int start_paths,
			int end_paths)
{
	t_list	*i;
	int		current;
	int		paths_at_start;
	int		paths_not_at_start;
	int		min_paths;

	i = paths;
	paths_at_start = 0;
	paths_not_at_start = 0;
	min_paths = start_paths < end_paths ? start_paths : end_paths;
	while (i)
	{
		current = gfp((int *)((t_list *)i->content)->content);
		if (current == start)
			paths_at_start++;
		else
			paths_not_at_start++;
		i = i->next;
	}
	return (paths_at_start < min_paths && paths_not_at_start);
}

static int	get_connecting_paths(t_rooms *rooms, int room)
{
	int	i;
	int	tr;

	i = 0;
	tr = 0;
	while (i < rooms->num_of_rooms)
	{
		if (rooms->paths[room][i] && i != room)
			tr++;
		i++;
	}
	return (tr);
}

t_list		*get_paths(t_rooms *rooms, int start, int end)
{
	t_list	*paths;
	int		start_paths;
	int		end_paths;

	paths = (t_list *)malloc(sizeof(t_list));
	paths->content = new_list(end);
	paths->content_size = 1;
	paths->next = NULL;
	start_paths = get_connecting_paths(rooms, start);
	end_paths = get_connecting_paths(rooms, end);
	while (can_continue(paths, start, start_paths, end_paths))
	{
		grow_paths(rooms, &paths, start);
		delete_dead_paths(&paths);
		find_start_paths(&paths, start, rooms);
		delete_dead_paths(&paths);
		find_shared_rooms(&paths, start);
		delete_dead_paths(&paths);
	}
	delete_non_starts(&paths, start);
	delete_dead_paths(&paths);
	fix_paths(&paths);
	return (paths);
}
