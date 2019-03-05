/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:20:08 by pdoherty          #+#    #+#             */
/*   Updated: 2019/03/03 08:24:57 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_index(char *name, t_rooms *rooms)
{
	int		i;
	char	**names;

	i = 0;
	names = rooms->room_names;
	while (names[i])
	{
		if (ft_strequ(names[i], name))
			return (i);
		i++;
	}
	send_error(1);
	return (-1);
}

void		free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void		add_link_to_list(t_rooms **rooms, char *line)
{
	char	**split;
	int		first;
	int		second;

	split = ft_strsplit(line, '-');
	free(line);
	send_error(!split[1] || split[2]);
	first = get_index(split[0], *rooms);
	second = get_index(split[1], *rooms);
	(*rooms)->paths[first][second] = 1;
	(*rooms)->paths[second][first] = 1;
	free_split(split);
}
