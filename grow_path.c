/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 08:51:35 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/08 14:04:07 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_copy(t_list *elem)
{
	t_list	*tr;
	int		content;

	if (!elem)
		return (NULL);
	content = gfp((int *)elem->content);
	tr = (t_list *)malloc(sizeof(t_list));
	tr->content = get_int_copy(content);
	tr->content_size = elem->content_size;
	tr->next = elem->next;
	return (tr);
}

static t_list	*copy_path(t_list *tr, t_list **paths, t_list *ta)
{
	t_list	*i;

	if (!tr)
		return (ta);
	i = ta;
	while (i)
	{
		i->next = get_copy(i->next);
		i = i->next;
	}
	ft_lstadd(paths, ta);
}

t_list			*grow_path(t_list **paths, t_list *path, t_rooms *rooms)
{
	t_list	*i;
	t_list	*tr;
	t_list	*ta;
	int		c;
	int		j;

	i = path;
	tr = NULL;
	while (i)
	{
		c = gfp((int *)i->content);
		j = 0;
		while (j < rooms->num_of_rooms)
		{
			if (j != c && rooms->paths[c][j] && !rooms->paths[j][j])
			{
				ta = new_list(get_int_copy(j));
				ta->next = i;
				ta->content_size = i->content_size + 1;
				tr = copy_path(tr, paths, ta);
					ft_lstadd(paths, copy_path(ta));
			}
			j++;
		}
		i = i->next;
	}
	return (tr);
}
