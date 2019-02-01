/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:30:32 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 11:39:21 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(int ant, char *name, int nl)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	if (nl)
		ft_putchar('\n');
	else
		ft_putchar(' ');
}

static void	move_ants(t_ants *ants, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = i->ant_list;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path_loc->next)
		{
			current->path_loc = current->path_loc->next;
			//TODO: Add to printing queue or something for sorting, or not
		}
		i = i->next;
	}
}

static void	add_ants(t_ants *ants, int *can_continue)
{
	int		needed;
	t_list	*i;

	needed = ants->ants > ants->ants_left ? ants->ants_left : ants->ants;
	i = ants->paths;
	while (needed > 0)
	{
		
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
		move_ants(ants, can_continue);
		add_ants(ants, can_continue);
	}
	delete_ants(ants);
}
