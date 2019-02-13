/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 08:51:35 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/13 13:49:31 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_copy(t_list *elem)
{
	t_list	*tr;
	int		content;
	int		*cp;

	if (!elem)
		return (NULL);
	content = gfp((int *)elem->content);
	cp = (int *)malloc(sizeof(int));
	*cp = content;
	tr = (t_list *)malloc(sizeof(t_list));
	tr->content = cp;
	tr->content_size = elem->content_size;
	tr->next = elem->next;
	return (tr);
}

static t_list	*copy_path(t_list *tr, t_list **paths, t_list *ta)
{
	t_list	*i;
	t_list	*to_add;

	if (!tr)
		return (ta);
	to_add = (t_list *)malloc(sizeof(t_list));
	to_add->content = ta;
	i = ta;
	while (i)
	{
		i->next = get_copy(i->next);
		i = i->next;
	}
	ft_lstadd(paths, to_add);
	return (tr);
}

t_list			*grow_path(t_list **paths, t_list *path, t_rooms *rooms)
{
	t_list	*tr;
	t_list	*ta;
	int		c;
	int		j;

	tr = NULL;
	c = gfp((int *)path->content);
	j = 0;
	while (j < rooms->num_of_rooms)
	{
		if (j != c && rooms->paths[c][j])
		{
			ta = new_list(j);
			ta->next = path;
			ta->content_size = path->content_size + 1;
			tr = copy_path(tr, paths, ta);
		}
		j++;
	}
	return (tr);
}
