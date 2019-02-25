/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_shared_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:20:10 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/24 08:34:39 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_last_room(t_list *path)
{
	t_list	*i;

	i = path;
	if (!i->next)
		return (-1);
	while (i->next && i->next->next)
		i = i->next;
	return (gfp((int *)i->content));
}

int			has_shared_path(t_list **paths, t_list *current)
{
	int		current_room;
	t_list	*i;
	t_list	*c;

	current_room = get_last_room(current);
	if (current_room == -1)
		return (0);
	i = *paths;
	while (i)
	{
		c = (t_list *)i->content;
		if (c != current && get_last_room(c) == current_room)
			return (1);
		i = i->next;
	}
	return (0);
}
