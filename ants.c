/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:24:10 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 11:26:37 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*new_ants(int ants)
{
	t_ants	*tr;

	tr = (t_ants *)malloc(sizeof(t_ants));
	tr->ant_list = NULL;
	tr->paths = NULL;
	tr->ants = ants;
	tr->ants_left = 0;
	return (tr);
}

//TODO: Make this actually delete the ants struct
void	delete_ants(t_ants *ants)
{
	delete_linked_list(tr->paths);
	delete_linked_list(tr->ant_list);
	free(ants);
}
