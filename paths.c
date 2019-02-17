/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/17 15:27:21 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	grow_paths(t_rooms *rooms, t_list **paths, int start)
{
	t_list	*i;
	t_list	*current;

	i = *paths;
	while (i)
	{
		current = (t_list *)i->content;
		if (gfp((int *)current->content) != start)
			i->content = grow_path(paths, current, rooms);
		i = i->next;
	}
}

void	remove_bad_paths(t_list **paths, int is_at_end, int *sae,
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
