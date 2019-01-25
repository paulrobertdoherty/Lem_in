/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:30:22 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/19 15:27:25 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*new_list(void const *content)
{
	t_list	*tr;

	tr = (t_list *)malloc(sizeof(t_list));
	tr->content = (void *)content;
	tr->content_size = sizeof(content);
	tr->next = NULL;
	return (tr);
}

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

static void	add_links(t_list **rooms, char *fl)
{
	char	*line;

	add_link_to_list(rooms, fl);
	while (will_continue(&line))
		add_link_to_list(rooms, line);
}

static void	set_start_and_end(t_room **start, t_room **end, t_room *ta,
			int mode)
{
	if (mode == 1)
		*start = ta;
	else if (mode == 2)
		*end = ta;
}

void		add_rooms(t_list **rooms, t_room **start, t_room **end)
{
	char	*line;
	t_room	*ta;
	int		mode;

	mode = 0;
	while (1)
	{
		gnl(&line);
		if (ft_strchr(line, '-') != NULL)
		{
			add_links(rooms, line);
			break ;
		}
		if (ft_strequ("##start", line))
			mode = free_with_return(line, 1);
		else if (ft_strequ("##end", line))
			mode = free_with_return(line, 2);
		else
		{
			ta = create_room(line);
			ft_lstadd(rooms, new_list(ta));
			set_start_and_end(start, end, ta, mode);
			mode = 0;
		}
	}
}
