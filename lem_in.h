/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/01/23 10:52:28 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "lem_in_types.h"

#include <stdio.h>

void	gnl(char **line);
void	add_rooms(t_list **rooms, t_room **start, t_room **end);
void	print_ants(int ants, t_room *start, t_room *end);
void	add_link_to_list(t_list **rooms, char *line);
void	free_split(char **split);
t_room	*create_room(char *line);
void	delete_link_list(t_list *list);
void	get_path(t_list **path, t_room *start, t_room *end);
t_list	*new_list(void const *content);
int		free_with_return(char *str, int r);
t_room	*get_current(t_list *links);
void	add_to_visiting(t_list *visiting, t_room *room);
void	remove_from_visiting(t_list *visiting, t_room *room);

#endif
