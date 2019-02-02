/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:20:08 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 19:40:40 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_link(t_list **rooms, char *name, t_room	*other)
{
	t_list	*i;
	t_room	*current;

	i = *rooms;
	while (i)
	{
		current = (t_room *)i->content;
		if (ft_strequ(current->name, name))
		{
			ft_lstadd(&(current->links), new_list(other));
			return (new_list(current));
		}
		i = i->next;
	}
	return (NULL);
}

void			free_split(char **split)
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

void			add_link_to_list(t_list **rooms, char *line)
{
	t_list	*i;
	t_room	*current;
	char	**split;

	split = ft_strsplit(line, '-');
	free(line);
	send_error(!split[1]);
	i = *rooms;
	while (i)
	{
		current = (t_room *)i->content;
		if (ft_strequ(current->name, split[0]))
		{
			ft_lstadd(&(current->links), get_link(rooms, split[1], current));
			break ;
		}
		i = i->next;
	}
	free_split(split);
}
