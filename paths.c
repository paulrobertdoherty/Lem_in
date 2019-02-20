/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/19 20:22:59 by pdoherty         ###   ########.fr       */
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
				((t_list *)i->content)->content_size = 0;
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

void		delete_dead_ends(t_list **paths)
{
	t_list	*i;
	t_list	*last;
	t_list	*current;

	i = *paths;
	last = NULL;
	while (i)
	{
		current = (t_list *)i->content;
		if (!current->content_size)
			delete_current(paths, current, &i, &last);
		else
		{
			last = i;
			i = i->next;
		}
	}
	send_error(*paths == NULL);
}

void		remove_bad_paths(t_list **paths, int is_at_end, int *sae,
			int end_paths)
{
	t_list	*i;
	t_list	*next;
	t_list	*content;

	i = *paths;
	while (i)
	{
		content = (t_list *)i->content;
		i->content_size = num_of_shared_rooms(content, paths, sae);
		i = i->next;
	}
	sort_paths(paths);
	i = move_to_next(*paths, is_at_end, end_paths);
	next = i->next;
	ft_lstdel(&next, &delete_paths);
	i->next = NULL;
}
