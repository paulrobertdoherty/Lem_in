/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:17:36 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/07 15:23:34 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*new_queue(void *content)
{
	t_queue	*tr;
	t_list	*first;

	tr = (t_queue *)malloc(sizeof(t_queue));
	first = (t_list *)malloc(sizeof(t_list));
	first->content = content;
	first->content_size = sizeof(content);
	first->next = NULL;
	tr->first = first;
	tr->last = first;
	return (tr);
}

void	push(t_queue *queue, void *content)
{
	t_list	*ta;

	if (!queue)
		return ;
	ta = (t_list *)malloc(sizeof(t_list));
	ta->content = content;
	ta->content_size = sizeof(content);
	ta->next = NULL;
	queue->last->next = ta;
	queue->last = ta;
}

void	*pop(t_queue *queue)
{
	void	*tr;
	t_list	*first;

	if (!queue || !queue->first)
		return (NULL);
	tr = queue->first->content;
	first = queue->first;
	queue->first = first->next;
	free(first);
	if (!queue->first)
		queue->last = NULL;
	return (tr);
}

void	*peek(t_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->content);
}

void	delete_queue(t_queue *queue, void (*del)(void *, size_t))
{
	if (!queue)
		return ;
	ft_lstdel(&(queue->first), del);
	free(queue);
}
