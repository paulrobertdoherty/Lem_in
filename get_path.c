/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:42:19 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/24 22:31:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_distance(t_room *start, t_room *end)
{
	t_list	*visiting;
	t_list	*i;
	t_room	*current;
	t_room	*c;

	visiting = start->links;
	while (1)
	{
		i = visiting;
		while (i)
		{
			c = (t_room *)i->content;
			if (ft_strequ(c->name, end->name))
				return ;
			current = get_current(c->links);
			if (c->distance == -1 || c->distance > current->distance + 1)
				c->distance = current->distance + 1;
			add_to_visiting(visiting, c->links);
			remove_from_visiting(visiting, c);
			i = i->next;
		}
	}
	delete_link_list(visiting);
}

void	get_path(t_list **path, t_room *start, t_room *end)
{
	start->distance = 0;
	start->visited = 1;
	find_distance(start, end);
	add_to_path(path, start, end);
}

//Breadth-first search
//Find distance between all links
//Create path from shortest distances
