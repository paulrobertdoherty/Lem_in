/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_long_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:40:43 by pdoherty          #+#    #+#             */
/*   Updated: 2019/03/02 10:59:48 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

static int	get_max_for(t_list *paths, int path_count, int *done)
{
	size_t	max_length;
	t_list	*il;
	int		i;

	i = 0;
	il = paths;
	max_length = 0;
	while (i < path_count && il)
	{
		if (il->content_size > max_length)
			max_length = il->content_size;
		i++;
		il = il->next;
	}
	if (i < path_count)
		*done = 1;
	max_length -= 1;
	return ((int)max_length);
}

static int	steps_produced_for(t_list *paths, int ants, int path_count,
			int *done)
{
	int	steps;
	int	max_for;

	max_for = get_max_for(paths, path_count, done);
	steps = max_for;
	ants -= path_count;
	steps += ants / path_count;
	if (ants % path_count > 0 &&
		get_max_for(paths, ants % path_count, done) == max_for)
			steps += 1;
	return (steps);
}

static int	num_of_paths(t_list *paths, int ants)
{
	int	num_of_paths;
	int	spf;
	int	lspf;
	int	done;

	num_of_paths = 2;
	done = 0;
	lspf = steps_produced_for(paths, ants, 1, &done);
	while (num_of_paths < ants && !done)
	{
		spf = steps_produced_for(paths, ants, num_of_paths, &done);
		if (spf > lspf)
			break ;
		lspf = spf;
		num_of_paths++;
	}
	return (num_of_paths - 1);
}

void		remove_long_paths(t_list **paths, int ants)
{
	t_list	*i;
	t_list	*last;
	int		c;
	int		nop;

	last = *paths;
	i = last->next;
	c = 1;
	nop = num_of_paths(last, ants);
	while (i)
	{
		if (c >= nop)
			break ;
		c++;
		last = i;
		i = i->next;
	}
	last->next = NULL;
	ft_lstdel(&i, &delete_paths);
}
