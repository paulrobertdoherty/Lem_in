/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:17:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/22 20:20:16 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_list(t_list *list)
{
	if (!list)
		return ;
	delete_list(list->next);
	free(list);
}

void	delete_non_starts(t_list **paths, int start)
{
	t_list	*i;

	i = *paths;
	while (i)
	{
		if (gfp((int *)((t_list *)i->content)->content) != start)
			i->content_size = 0;
		i = i->next;
	}
}

void	fix_paths(t_list **paths)
{
	t_list	*i;

	i = *paths;
	while (i)
	{
		i->content_size = ((t_list *)i->content)->content_size;
		i = i->next;
	}
}
