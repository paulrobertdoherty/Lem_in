/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:13:40 by pdoherty          #+#    #+#             */
/*   Updated: 2019/03/01 13:07:46 by pdoherty         ###   ########.fr       */
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
void	send_error(int b);
void	delete_generic(void *content, size_t content_size);
void	delete_paths(void *content, size_t content_size);
t_rooms	*new_rooms(void);
void	add_rooms_to_array(t_rooms **rooms, int *start, int *end);
void	free_rooms(t_rooms *rooms);
t_list	*new_list(int n);
int		gfp(int *p);
t_list	*get_connecting_rooms(int visiting, t_rooms *rooms, int end);
t_list	*get_path(t_rooms *rooms, int end, int *room_pointers);
void	remove_visited(t_rooms *rooms, int start);
t_queue	*new_t_queue(void);
void	push(t_queue *queue, t_list *ta);
t_list	*pop(t_queue *queue);
int		is_empty(t_queue *queue);
t_list	*peek(t_queue *queue);
void	remove_long_paths(t_list **paths, int ants);
void	sort_paths(t_list **paths);
int		pop_to_visit(t_queue *to_visit);

#endif
