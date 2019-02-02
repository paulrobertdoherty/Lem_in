/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:24:10 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 17:22:47 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants		*new_ants(int ants)
{
	t_ants	*tr;

	tr = (t_ants *)malloc(sizeof(t_ants));
	tr->ant_list = NULL;
	tr->paths = NULL;
	tr->ants = ants;
	tr->ants_left = ants;
	return (tr);
}

static void	delete_ant(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

void		delete_ants(t_ants *ants)
{
	ft_strdel(&(tr->paths), &delete_ant);
	delete_linked_list(tr->ant_list);
	free(ants);
}
