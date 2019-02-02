/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:54:55 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/01 17:22:50 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_TYPES_H
# define LEM_IN_TYPES_H

typedef struct	s_room
{
	char		name;
	int			visited;
	t_list		*links;
}				t_room;

typedef struct	s_path
{
	t_list		*rooms;
	int			shared;
	int			length;
	int			ants_in_path;
}				t_path;

typedef struct	s_ant
{
	t_list		*path_loc;
	int			n;
}				t_ant;

typedef struct	s_ants
{
	t_list		*ant_list;
	t_list		*paths;
	int			ants;
	int			ants_left;
}

#endif
