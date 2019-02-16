/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:48:50 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/16 12:10:31 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	*get_rooms(int n)
{
	int	*tr;
	int	i;

	tr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		tr[i] = 0;
		i++;
	}
	return (tr);
}

void		delete_generic(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_rooms	*new_rooms(void)
{
	t_rooms	*tr;

	tr = (t_rooms *)malloc(sizeof(t_rooms));
	tr->paths = NULL;
	tr->num_of_rooms = 0;
	tr->room_names = NULL;
	tr->room_name_list = NULL;
	return (tr);
}

void		add_rooms_to_array(t_rooms **rooms, int *start, int *end)
{
	t_rooms	*r;
	t_list	*j;
	int		i;

	r = *rooms;
	r->paths = (int **)malloc(sizeof(int *) * r->num_of_rooms);
	r->room_names = (char **)malloc(sizeof(int *) * (1 + r->num_of_rooms));
	i = 0;
	j = r->room_name_list;
	while (i < r->num_of_rooms)
	{
		r->paths[i] = get_rooms(r->num_of_rooms);
		r->room_names[i] = ft_strdup((char *)j->content);
		j = j->next;
		i++;
	}
	r->room_names[i] = NULL;
	ft_lstdel(&(r->room_name_list), &delete_generic);
	r->room_name_list = NULL;
	*start = r->num_of_rooms - (1 + *start);
	*end = r->num_of_rooms - (1 + *end);
}

void		free_rooms(t_rooms *rooms)
{
	int	i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		free(rooms->room_names[i]);
		free(rooms->paths[i]);
		i++;
	}
	free(rooms->room_names);
	free(rooms->paths);
	free(rooms);
}
