/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/09 15:43:31 by pdoherty         ###   ########.fr       */
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

void	remove_bad_paths(t_rooms *rooms, t_list **paths, int is_at_end,
						int end_paths)
{
	t_list	*i;
	int		j;

	i = *paths;
	while (i)
	{
		i->content_size = num_of_shared_rooms((t_list *)i->content, paths);
		i = i->next;
	}
	sort_paths(paths);
	i = paths;
	j = 0;
	while (i)
	{
		if (j == end_paths)
			break ;

		i = i->next;
	}
}
