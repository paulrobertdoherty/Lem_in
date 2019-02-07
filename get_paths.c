/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:50:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/07 08:54:10 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*new_list(void *content)
{
	t_list	*tr;

	tr = (t_list *)malloc(sizeof(t_list));
	tr->content = content;
	tr->content_size = sizeof(content);
	tr->next = NULL;
	return tr;
}

static void		*get_int_copy(int n)
{
	int	*tr;

	tr = (int *)malloc(sizeof(int));
	*tr = n;
	return tr;
}

//This is just a test, of course
t_list			*get_paths(t_rooms *rooms, int start, int end, int ants)
{
	t_list	*tr = NULL;
	int	c = end;
	rooms->paths[end][end] = 1;
	while (c != start) {
		ft_lstadd(&tr, new_list(get_int_copy(c)));
		for (int i = 0; i < rooms->num_of_rooms; i++) {
			if (rooms->paths[c][i] && !(rooms->paths[i][i])) {
				rooms->paths[i][i] = 1;
				c = i;
				break ;
			}
		}
	}
	ft_lstadd(&tr, new_list(get_int_copy(c)));
	ants = 0;
	return new_list(tr);
}
