/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:50:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/18 09:24:23 by pdoherty         ###   ########.fr       */
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

static int	can_continue(t_list *paths, int start, int end_paths)
{
	t_list	*i;
	int		current;
	int		paths_at_start;
	int		paths_not_at_start;

	i = paths;
	paths_at_start = 0;
	paths_not_at_start = 0;
	while (i)
	{
		current = gfp((int *)((t_list *)i->content)->content);
		if (current == start)
			paths_at_start++;
		else
			paths_not_at_start++;
		i = i->next;
	}
	return (paths_at_start < end_paths && paths_not_at_start);
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
	int		*sae;

	paths = (t_list *)malloc(sizeof(t_list));
	paths->content = new_list(end);
	paths->next = NULL;
	end_paths = get_end_paths(rooms, end);
	sae = get_sae(start, end);
	while (can_continue(paths, start, end_paths))
	{
		grow_paths(rooms, &paths, start);
		remove_bad_paths(&paths, 0, sae, end_paths);
	}
	remove_bad_paths(&paths, 1, sae, end_paths);
	fix_paths(&paths);
	free(sae);
	return (paths);
}
