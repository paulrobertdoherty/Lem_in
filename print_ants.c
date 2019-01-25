/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:30:32 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/19 18:41:08 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_ant_path(t_list *path, t_list **ant_start, t_list **ant_end,
			int ants)
{
	t_list	*i;
	int		j;

	*ant_start = path;
	i = *ant_start;
	j = 1;
	while (j < ants)
	{
		j++;
		if (i->next)
			i = i->next;
	}
	*ant_end = i;
}

static int	move_ants(t_list **ant_start, t_list **ant_end, int *start_ants,
			int *end_ants)
{
	if (*start_ants > 0)
	{
		(*start_ants)--;
		if ((*ant_end)->next == NULL)
			(*end_ants)++;
	}
	else
	{
		if ((*ant_end)->next == NULL)
			(*end_ants)++;
		else
		{
			*ant_start = (*ant_start)->next;
			*ant_end = (*ant_end)->next;
		}
	}
	return (1);
}

static void	print_ant(int ant, char *room_name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room_name);
	ft_putchar(' ');
}

static void	print_path(t_list **ant_start, int start_ants, int end_ants,
			int ants)
{
	t_list	*i;
	int		ant;
	int		printed;

	ant = start_ants;
	i = *ant_start;
	printed = 0;
	while (ant < ants)
	{
		if (ant - end_ants >= 0 && i)
		{
			print_ant((end_ants < 0 ? 0 : end_ants) + ants - ant,
					((t_room *)i->content)->name);
			printed = 1;
		}
		if (i)
			i = i->next;
		else
			break ;
		ant++;
	}
	if (printed)
		ft_putchar('\n');
}

void		print_ants(int ants, t_room *start, t_room *end)
{
	t_list	*path;
	t_list	*ant_start;
	t_list	*ant_end;
	int		start_ants;
	int		end_ants;

	if (!ants)
		return ;
	path = NULL;
	get_path(&path, start, end);
	if (!path)
		return ;
	start_ants = ants;
	end_ants = -ants;
	set_ant_path(path, &ant_start, &ant_end, ants);
	while (move_ants(&ant_start, &ant_end, &start_ants, &end_ants) &&
		end_ants < ants)
		print_path(&ant_start, start_ants, end_ants, ants);
	delete_link_list(path);
}
