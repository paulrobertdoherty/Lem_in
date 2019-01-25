/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:54:55 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/23 11:16:00 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_TYPES_H
# define LEM_IN_TYPES_H

typedef struct	s_room
{
	char		name;
	int			x;
	int			y;
	int			distance;
	int			visited;
	t_list		*links;
}				t_room;

typedef struct	s_hash_map
{
	t_list		**table;
	int			buckets;
}				t_hash_map;

#endif
