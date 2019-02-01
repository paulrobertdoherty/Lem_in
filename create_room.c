/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:56:45 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/31 14:00:04 by pdoherty         ###   ########.fr       */
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
	tr->name = ft_strdup(split[0]);
	free_split(split);
	tr->links = NULL;
	return (tr);
}
