/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:31 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/19 18:10:59 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char	*line;
	int		tr;

	gnl(&line);
	tr = ft_atoi(line);
	free(line);
	return (tr);
}

void		delete_link_list(t_list *links)
{
	if (links->next)
		delete_link_list(links->next);
	free(links);
}

static void	delete_room(void *content, size_t content_size)
{
	t_room	*room;

	room = (t_room *)content;
	free(room->name);
	delete_link_list(room->links);
	free(room);
	content_size = 0;
}

int			main(void)
{
	int		ants;
	t_list	*rooms;
	t_room	*start;
	t_room	*end;

	ants = get_ants();
	rooms = NULL;
	start = NULL;
	end = NULL;
	add_rooms(&rooms, &start, &end);
	print_ants(ants, start, end);
	ft_lstdel(&rooms, &delete_room);
	return (0);
}
