/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:30:32 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/05 17:07:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(t_ant *ant, t_rooms *rooms)
{
	int		n;
	char	*name;

	n = ant->n;
	name = rooms->room_names[(int)ant->path->content];
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

static void	move_ants(t_list *ants, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = ants;
	*can_continue = 0;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path->next)
		{
			*can_continue = 1;
			current->path = current->path->next;
			print_ant(current);
		}
		i = i->next;
	}
}

static void	add_ants(t_list *paths, t_list *ants, int *ants_left,
			int *can_continue)
{
	t_list	*i;
	t_ant	*ta;

	if (*ants_left < 1)
		return ;
	i = paths;
	while (i && ants->ants_left >= 1)
	{
		ta = (t_ant *)malloc(sizeof(t_ant));
		ta->path = i;
		ta->n = (ants->ants - ants->ants_left) + 1;
		ft_lstadd(&ants, new_list(ta));
		(*ants_left)--;
		print_ant(ta);
		*can_continue = 1;
		i = i->next;
	}
}

void		print_ants(int ants, int start, int end, t_rooms *rooms)
{
	t_list	*paths;
	t_list	*ant_list;
	int		can_continue;

	if (!ants)
		return ;
	paths = get_paths(rooms, start, end, ants);
	if (!paths)
		return ;
	sort_paths(paths);
	ant_list = NULL;
	can_continue = 1;
	while (can_continue)
	{
		move_ants(ant_list, rooms, &can_continue);
		add_ants(ant_list, paths, rooms, &can_continue);
		ft_putchar('\n');
	}
	delete_paths(paths);
}
