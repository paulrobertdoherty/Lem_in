/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:30:32 by pdoherty          #+#    #+#             */
/*   Updated: 2019/03/02 19:50:29 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(t_ant *ant, t_rooms *rooms)
{
	int		n;
	int		*room_pointer;
	char	*name;

	n = ant->n;
	room_pointer = (int *)ant->path->content;
	name = rooms->room_names[*room_pointer];
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

static void	move_ants(t_list **ants, t_rooms *rooms, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = *ants;
	*can_continue = 0;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path->next)
		{
			*can_continue = 1;
			current->path = current->path->next;
			print_ant(current, rooms);
		}
		i = i->next;
	}
}

static int	add_ants(t_list *paths, t_list **ant_list, int ants, int *ants_left)
{
	t_list	*i;
	t_ant	*ta;
	t_list	*tal;
	int		tr;

	if (*ants_left < 1)
		return (0);
	i = paths;
	tr = 0;
	while (i && i->content_size && *ants_left >= 1)
	{
		ta = (t_ant *)malloc(sizeof(t_ant));
		ta->path = (t_list *)i->content;
		ta->n = (ants - *ants_left) + 1;
		tal = (t_list *)malloc(sizeof(t_list));
		tal->content = ta;
		tal->content_size = sizeof(ta);
		ft_lstadd(ant_list, tal);
		(*ants_left)--;
		tr = 1;
		i->content_size--;
		i = i->next;
	}
	return (tr);
}

void		delete_paths(void *content, size_t content_size)
{
	t_list	*ts;

	ts = (t_list *)content;
	content_size = 0;
	ft_lstdel(&ts, &delete_generic);
}

void		print_ants(int ants, int start, int end, t_rooms *rooms)
{
	t_list	*paths;
	t_list	*ant_list;
	int		can_continue;
	int		ants_left;

	if (!ants)
		return ;
	paths = get_paths(rooms, start, end);
	send_error(!paths);
	sort_paths(&paths);
	find_path_capacity(paths, ants);
	write_paths_file(paths, rooms);
	ant_list = NULL;
	can_continue = 1;
	ants_left = ants;
	while (can_continue)
	{
		move_ants(&ant_list, rooms, &can_continue);
		if (ant_list && can_continue)
			ft_putchar('\n');
		can_continue = add_ants(paths, &ant_list, ants, &ants_left)
					|| can_continue;
	}
	ft_lstdel(&paths, &delete_paths);
	ft_lstdel(&ant_list, &delete_generic);
}
