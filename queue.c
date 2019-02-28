/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:35:30 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/28 14:39:43 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue *new_t_queue(void)
{
	t_queue	*tr;

	tr = (t_queue *)malloc(sizeof(t_queue));
	tr->first = NULL;
	tr->last = NULL;
	return (tr);
}

int		is_empty(t_queue *queue)
{
	return (queue->first == NULL);
}

void	push(t_queue *queue, t_list *ta)
{
	if (is_empty(queue))
	{
		queue->first = ta;
		queue->last = ta;
	}
	else
	{
		queue->last->next = ta;
		queue->last = ta;
	}
}

t_list	*pop(t_queue *queue)
{
	t_list	*tr;

	if (is_empty(queue))
		return (NULL);
	tr = queue->first;
	queue->first = queue->first->next;
	return (tr);
}

t_list	*peek(t_queue *queue)
{
	return (queue->first);
}
