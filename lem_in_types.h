/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:54:55 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/06 11:57:32 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_TYPES_H
# define LEM_IN_TYPES_H

typedef struct	s_rooms
{
	int			**paths;
	int			num_of_rooms;
	char		**room_names;
	t_list		*room_name_list;
}				t_rooms;

typedef struct	s_ant
{
	int			n;
	t_list		*path;
}				t_ant;

#endif
