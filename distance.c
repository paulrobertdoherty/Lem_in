/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:51:48 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/24 22:31:36 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_current(t_list *links)
{
	t_list	*i;
	t_room	*tr;
	t_room	*current;

	i = links;
	tr = NULL;
	while (i)
	{
		current = (t_room *)i->content;
		if (current->visited && (!tr || tr->distance > current->distance))
			tr = current;
		i = i->next;
	}
	return (tr);
}

//TODO: Hashmap here, maybe
static void atv(t_room *link, t_list *visiting, int *a)
{
	t_list	*i;
	t_list	*li;
	t_room	*current;

	i = visiting;
	li = NULL;
	while (i)
	{
		current = (t_room *)i->current;
		if (!current->visited && !ft_strequ(link->name, current->name))
			
		li = i;
		i = i->next;
	}
}

//TODO: Hashmap here, maybe
void	add_to_visiting(t_list *visiting, t_list *links)
{
	t_list	*i;
	t_room	*ic;
	int		a;

	i = links;
	while (i)
	{
		ic = (t_room *)i->content;
		a = !(ic->visited);
		atv(ic, visiting, &a);
		if (a && j)
			
		i = i->next;
	}
}

void	remove_from_visiting(t_list *visiting, t_list *links)
{
	
}
