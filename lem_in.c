/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:31 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/03 19:16:16 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char	*line;
	int		tr;

	gnl(&line);
	tr = ft_atoi(line);
	free(line);
	send_error(!tr);
	return (tr);
}

int			main(void)
{
	t_rooms	*rooms;
	int		ants;
	int		start;
	int		end;

	ants = get_ants();
	rooms = NULL;
	add_rooms(&rooms, &start, &end);
	print_ants(ants, start, end, rooms);
	free_rooms(rooms);
	return (0);
}
