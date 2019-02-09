/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/09 14:20:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "lem_in_types.h"

//TODO: Delete this
#include <stdio.h>

void	gnl(char **line);
void	add_rooms(t_rooms **rooms, int *start, int *end);
void	print_ants(int ants, int start, int end, t_rooms *rooms);
void	add_link_to_list(t_rooms **rooms, char *line);
void	free_split(char **split);
t_list	*get_paths(t_rooms *rooms, int start, int end);
int		free_with_return(char *str, int r);
void	sort_paths(t_list *paths);
void	send_error(int b);
void	delete_generic(void *content, size_t content_size);
t_rooms	*new_rooms(void);
void	add_rooms_to_array(t_rooms **rooms, int *start, int *end);
void	free_rooms(t_rooms *rooms);
t_list	*new_list(int n);
int		gfp(int *p);
t_list	*grow_path(t_list **paths, t_list *path, t_rooms *rooms);

#endif
