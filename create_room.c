/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:56:45 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 17:56:25 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(char *line)
{
	char	**split;
	t_room	*tr;

	tr = (t_room *)malloc(sizeof(t_room));
	tr->visited = 0;
	split = ft_strsplit(line, ' ');
	free(line);
	send_error(!split[1]);
	tr->name = ft_strdup(split[0]);
	free_split(split);
	tr->links = NULL;
	return (tr);
}
