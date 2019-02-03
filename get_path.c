/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:59:07 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/03 10:56:55 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**Adds all the links from the end room into a 
*/
static void	init_path(t_list **paths, t_room *end)
{
	t_list	*i;

	i = end->links;
	while (i)
	{
		ft_lstadd(paths, new_list(i->content));
		i = i->next;
	}
}

/*
**Checks if at least one of the rooms has not yet reached the start.
**If so, then continue the while loop. Otherwise, stop it.
*/
static int	paths_are_incomplete(t_list **paths, t_room *start)
{
	t_list	*i;
	t_room	*current;

	i = *paths;
	while (i)
	{
		current = (t_room *)i->content;
		if (!ft_strequ(current->name, start->name))
			return (1);
		i = i->next;
	}
	return (0);
}

static void	grow_paths(t_list **paths)
{
	
}

static void	delete_paths(t_list **paths, int num_of_paths, int is_at_start)
{
	t_list	*i;
	t_list	*li;

	i = *paths;
	li = NULL;
	while (i)
	{

		li = i;
		i = i->next;
	}
}

void		get_paths(t_list **paths, t_room *start, t_room *end, int ants)
{
	int		num_of_paths;

	if (get_shortest(paths, start, end, ants))
		return ;
	num_of_paths = ft_get_lst_size(end->links);
	init_path(path, end);
	while (paths_are_incomplete(paths, start))
	{
		grow_paths(paths);
		delete_paths(paths, num_of_paths, 0);
	}
	delete_paths(paths, num_of_paths, 1);
}
