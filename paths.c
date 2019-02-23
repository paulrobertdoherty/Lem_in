/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/22 20:16:58 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		grow_paths(t_rooms *rooms, t_list **paths, int start)
{
	t_list	*i;
	t_list	*current;
	t_list	*new_list;
	int		paths_grown;

	i = *paths;
	paths_grown = 0;
	while (i)
	{
		current = (t_list *)i->content;
		if (gfp((int *)current->content) != start)
		{
			new_list = grow_path(paths, current, rooms);
			if (new_list)
			{
				i->content = new_list;
				paths_grown++;
			}
			else
				i->content_size = 0;
		}
		i = i->next;
	}
	send_error(!paths_grown);
}

static void	delete_current(t_list **paths, t_list *current, t_list **i,
			t_list **last)
{
	ft_lstdel(&current, &delete_generic);
	current = *i;
	*i = (*i)->next;
	free(current);
	if (*last == NULL)
		*paths = *i;
	else
		(*last)->next = *i;
}

void		delete_dead_paths(t_list **paths)
{
	t_list	*i;
	t_list	*last;

	i = *paths;
	last = NULL;
	while (i)
	{
		if (!i->content_size)
			delete_current(paths, (t_list *)i->content, &i, &last);
		else
		{
			last = i;
			i = i->next;
		}
	}
	send_error(*paths == NULL);
}

void		find_start_paths(t_list **paths, int start, int end,
			t_rooms *rooms)
{
	t_list	*i;
	t_list	*current;

	i = *paths;
	while (i)
	{
		current = (t_list *)i->content;
		if (i->content_size && gfp((int *)current->content) == start)
			find_start_for_path(paths, current, start, rooms);
		i = i->next;
	}
	end = 0;
}

void		find_shared_rooms(t_list **paths, int start, int end,
			t_rooms *rooms)
{
	t_list	*i;
	t_list	*current;

	i = *paths;
	while (i)
	{
		current = (t_list *)i->content;
		if (has_shared_room(paths, current, rooms))
			i->content_size = 0;
		i = i->next;
	}
	start = 0;
	end = 0;
}
