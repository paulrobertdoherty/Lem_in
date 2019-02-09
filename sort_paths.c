/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:13:12 by pdoherty          #+#    #+#             */
/*   Updated: 2019/02/08 16:40:24 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	compare(t_list **paths_arr, int i, int j)
{
	size_t	first;
	size_t	second;

	first = paths_arr[i]->content_size;
	second = paths_arr[j]->content_size;
	return (first > second);
}

static void	combine(t_list **paths_arr, int s, int m, int e)
{
	t_list	**temp;
	int		i;
	int		j;
	int		k;

	temp = (t_list **)malloc(sizeof(t_list *) * (2 + e - s));
	temp[1 + e - s] = NULL;
	i = s;
	j = m + 1;
	k = 0;
	while (k < 1 + e - s)
	{
		if (compare(paths_arr, i, j))
			temp[k++] = paths_arr[j];
		else
			temp[k++] = paths_arr[i];
		if (i < m)
			i++;
		if (j < e)
			j++;	
	}
	i = s;
	k = 0;
	while (temp[k])
		paths_arr[i++] = temp[k++];
	free(temp);
}

static void	merge_sort(t_list **paths_arr, int s, int e)
{
	int	m;

	if (s < e)
	{
		m = (s + e) / 2;
		merge_sort(paths_arr, s, m);
		merge_sort(paths_arr, m + 1, e);
		combine(paths_arr, s, m, e);
	}
}

void		sort_paths(t_list **paths)
{
	t_list	**paths_arr;
	t_list	*i;
	int		j;
	int		size;

	if (!(*paths))
		return ;
	paths_arr = ft_lst_to_array(*paths, &size);
	merge_sort(paths_arr, 0, size - 1);
	i = paths_arr[0];
	j = 1;
	while (j < size)
	{
		i->next = paths_arr[j];
		i = i->next;
		j++;
	}
	i->next = NULL;
	free(paths_arr);
}
