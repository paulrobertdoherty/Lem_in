/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/25 07:18:37 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "lem_in_types.h"

void	gnl(char **line);
void	add_rooms(t_rooms **rooms, int *start, int *end);
void	print_ants(int ants, int start, int end, t_rooms *rooms);
void	add_link_to_list(t_rooms **rooms, char *line);
void	free_split(char **split);
t_list	*get_paths(t_rooms *rooms, int start, int end);
int		free_with_return(char *str, int r);
void	sort_paths(t_list **paths);
void	send_error(int b);
void	delete_generic(void *content, size_t content_size);
t_rooms	*new_rooms(void);
void	add_rooms_to_array(t_rooms **rooms, int *start, int *end);
void	free_rooms(t_rooms *rooms);
t_list	*new_list(int n);
int		gfp(int *p);
t_list	*grow_path(t_list **paths, t_list *path, t_rooms *rooms);
void	delete_paths(void *content, size_t content_size);
void	grow_paths(t_rooms *rooms, t_list **paths, int start);
void	delete_dead_ends(t_list **paths);
void	delete_dead_paths(t_list **paths);
void	find_start_paths(t_list **paths, int start, t_rooms *rooms);
void	find_shared_rooms(t_list **paths, int start);
void	find_start_for_path(t_list **paths, t_list *path, int s, t_rooms *r);
int		has_shared_room(t_list **paths, t_list *path, int start);
void	fix_paths(t_list **paths);
void	delete_list(t_list *list);
void	delete_non_starts(t_list **paths, int start);
int		has_shared_path(t_list **paths, t_list *current);
void	remove_long_paths(t_list **paths, int ants);

#endif
