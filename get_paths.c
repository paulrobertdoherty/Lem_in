/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:50:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/11 13:06:57 by pdoherty         ###   ########.fr       */
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
	return tr;
}

/*
**An easy way to get an int from an int pointer. It's for aesthetics
*/
int			gfp(int *p)
{
	return (*p);
}

static int	can_continue(t_list *paths, int start, int path_count)
{
	t_list	*i;
	int		current;
	int		start_paths;

	i = paths;
	start_paths = 0;
	while (i)
	{
		current = gfp((int *)((t_list *)i->content)->content);
		if (current == start)
			start_paths++;
		if (start_paths == path_count)
			return (0);
		i = i->next;
	}
	return (1);
}

static int	get_end_paths(t_rooms *rooms, int end)
{
	int	i;
	int	tr;

	i = 0;
	tr = 0;
	while (i < rooms->num_of_rooms)
	{
		if (rooms->paths[end][i] && i != end)
			tr++;
		i++;
	}
	return (tr);
}

t_list		*get_paths(t_rooms *rooms, int start, int end)
{
	t_list	*paths;
	int		end_paths;

	paths = (t_list *)malloc(sizeof(t_list));
	paths->content = new_list(end);
	paths->next = NULL;
	end_paths = get_end_paths(rooms, end);
	while (can_continue(paths, start, end_paths))
	{
		set_visiting_to_visited(rooms, paths);
		grow_paths(rooms, &paths);
		remove_bad_paths(&paths, 0, end, end_paths);
	}
	remove_bad_paths(&paths, 1, end, end_paths);
	return (paths);
}
