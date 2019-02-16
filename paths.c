/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/16 14:07:22 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	t_list	*next;
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
	{
		i = move_to_next(i);
		next = i->next;
	}
	else
		next = i->next;
	ft_lstdel(&next, &delete_paths);
	i->next = NULL;
}
