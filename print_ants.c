/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:30:32 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 20:56:33 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(t_ant * ant)
{
	int		n;
	char	*name;

	n = ant->n;
	name = ((t_room *)ant->path_loc->content)->name;
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

static void	move_ants(t_ants *ants, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = ants->ant_list;
	*can_continue = 0;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path_loc->next)
		{
			*can_continue = 1;
			current->path_loc = current->path_loc->next;
			print_ant(current);
		}
		i = i->next;
	}
}

static void	add_ants(t_ants *ants, int *can_continue)
{
	t_list	*i;
	t_ant	*ta;

	if (ants->ants_left < 1)
		return ;
	i = ants->paths;
	while (i && ants->ants_left >= 1)
	{
		ta = (t_ant *)malloc(sizeof(t_ant));
		ta->path_loc = i;
		ta->n = (ants->ants - ants->ants_left) + 1;
		ft_lstadd(&(ants->ant_list), new_list(ta));
		ants->ants_left--;
		print_ant(ta);
		*can_continue = 1;
		i = i->next;
	}
}

void		print_ants(int ant_c, t_room *start, t_room *end)
{
	t_ants	*ants;
	int		can_continue;

	if (!ant_c)
		return ;
	ants = new_ants(ant_c);
	get_paths(&(ants->paths), start, end, ant_c);
	if (!ants->paths)
		return ;
	sort_paths(ants->paths);
	can_continue = 1;
	while (can_continue)
	{
		move_ants(ants, &can_continue);
		add_ants(ants, &can_continue);
		ft_putchar('\n');
	}
	delete_ants(ants);
}
