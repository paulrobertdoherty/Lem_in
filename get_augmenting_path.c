/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_augmenting_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:08:03 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/28 15:01:56 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_connecting_rooms(int visiting, t_rooms *rooms)
{
	t_list	*room_list;
	int		i;

	room_list = NULL;
	i = 0;
	while (i < rooms->num_of_rooms)
	{
		if (rooms->paths[visiting][i] && i != visiting && !rooms->paths[i][i])
			ft_lstadd(&room_list, new_list(i));
		i++;
	}
	return (room_list);
}

//TODO: Fill capacity when creating path
t_list	*get_path(t_rooms *rooms, int end, int *room_pointers)
{
	t_list	*path;
	t_list	*wrapper;
	int		c;

	//For -Wall -Werror -Wextra
	path = rooms ? NULL : NULL;
	c = end;
	while (room_pointers[c] != c)
	{
		ft_lstadd(&path, new_list(c));
		c = room_pointers[c];
	}
	if (path == NULL)
		return (NULL);
	wrapper = (t_list *)malloc(sizeof(t_list));
	wrapper->content = path;
	wrapper->next = NULL;
	return (wrapper);
}
