/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:16:02 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/19 15:20:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	gnl(char **line)
{
	char	*l;

	while (1)
	{
		get_next_line(0, &l);
		if (l[0] != '#' || ft_strequ("##start", l) || ft_strequ("##end", l))
		{
			*line = l;
			ft_putstr(l);
			ft_putchar('\n');
			break ;
		}
		free(l);
	}
}
