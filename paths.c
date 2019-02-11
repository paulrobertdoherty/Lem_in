/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/11 14:05:54 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_visiting_to_visited(t_rooms *rooms, t_list *paths)
{
	t_list	*i;
	int		c;

	i = paths;
	while (i)
	{
		c = gfp((int *)((t_list *)i->content)->content);
		rooms->paths[c][c] = 1;
		i = i->next;
	}
}

void	grow_paths(t_rooms *rooms, t_list **paths)
{
	t_list	*i;

	i = *paths;
	while (i)
	{
		i->content = grow_path(paths, (t_list *)i->content, rooms);
		i = i->next;
	}
}

void	remove_bad_paths(t_list **paths, int is_at_end,
						int end, int end_paths)
{
	t_list	*i;
	t_list	*content;

	i = *paths;
	while (i)
	{
		content = (t_list *)i->content;
		i->content_size = num_of_shared_rooms(content, paths, end);
		i = i->next;
	}
	sort_paths(paths);
	i = get_last_path(paths, end_paths);
	if (!is_at_end)
		i = move_to_next(i);
	else
		i = i->next;
	ft_lstdel(&i, &delete_paths);
}
