/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:12:48 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/11 14:12:55 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
