/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:30:22 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/24 15:30:03 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	will_continue(char **line)
{
	gnl(line);
	if (!ft_strlen(*line))
	{
		free(*line);
		return (0);
	}
	return (1);
}

static void	add_links(t_rooms **rooms, char *fl, int *start, int *end)
{
	char	*line;

	send_error(*start == -1 || *end == -1);
	add_rooms_to_array(rooms, start, end);
	add_link_to_list(rooms, fl);
	while (will_continue(&line))
		add_link_to_list(rooms, line);
}

static void	set_start_and_end(int *start, int *end, int ta, int *mode)
{
	if (*mode == 1)
		*start = ta;
	else if (*mode == 2)
		*end = ta;
	*mode = 0;
}

static int	add_new_room(t_rooms *rooms, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	send_error(!split[1]);
	free(line);
	ft_lstadd(&(rooms->room_name_list), ft_lstnew(split[0], sizeof(split[0])));
	free_split(split);
	rooms->num_of_rooms++;
	return (rooms->num_of_rooms - 1);
}

void		add_rooms(t_rooms **rooms, int *start, int *end)
{
	char	*line;
	int		mode;

	*rooms = new_rooms();
	mode = 0;
	while (1)
	{
		gnl(&line);
		if (ft_strchr(line, '-') != NULL)
		{
			add_links(rooms, line, start, end);
			break ;
		}
		if (ft_strequ("##start", line))
			mode = free_with_return(line, 1);
		else if (ft_strequ("##end", line))
			mode = free_with_return(line, 2);
		else
			set_start_and_end(start, end, add_new_room(*rooms, line), &mode);
	}
}
