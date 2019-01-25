/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:25:31 by pdoherty          #+#    #+#             */
/*   Updated: 2018/12/08 18:00:16 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	new_line_index(char *str, int *has_nl)
{
	size_t	nli;

	nli = 0;
	while (str[nli])
	{
		if (str[nli] == '\n')
		{
			*has_nl = 1;
			return (nli);
		}
		nli++;
	}
	*has_nl = 0;
	return (nli);
}

static int		add_to_tr(char **tr, char *ta)
{
	char	*new_tr;
	char	*new_ta;
	int		has_nl;

	new_ta = ft_strsub(ta, 0, new_line_index(ta, &has_nl));
	new_tr = ft_strjoin(*tr, new_ta);
	free(new_ta);
	free(*tr);
	*tr = new_tr;
	return (!has_nl);
}

static int		rot_leftover(char **leftover, char **line, char *tr)
{
	char	*new_leftover;
	int		has_nl;
	size_t	nli;

	nli = new_line_index(*leftover, &has_nl);
	if (has_nl)
		new_leftover = ft_strsub(*leftover, nli + 1,
				ft_strlen(*leftover) - nli);
	else
		new_leftover = ft_strnew(0);
	free(*leftover);
	*leftover = new_leftover;
	*line = tr;
	return (1);
}

static int		add_to_leftover(char **leftover, char *buffer, int c,
		size_t t)
{
	char	*new_leftover;
	size_t	nli;
	int		has_nl;

	if (!c && t == 0)
	{
		ft_strdel(leftover);
		return (0);
	}
	nli = new_line_index(buffer, &has_nl);
	if (has_nl && c)
		new_leftover = ft_strsub(buffer, nli + 1,
				ft_strlen(buffer) - nli);
	else
		new_leftover = ft_strnew(0);
	free(*leftover);
	*leftover = new_leftover;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*leftover[4000];
	char		*tr;
	char		buffer[BUFF_SIZE + 1];
	int			c;

	if (fd < 0 || fd >= 4000 || line == NULL)
		return (-1);
	tr = ft_strnew(0);
	if (leftover[fd] == NULL)
		leftover[fd] = ft_strnew(0);
	if (!add_to_tr(&tr, leftover[fd]))
		return (rot_leftover(&leftover[fd], line, tr));
	while ((c = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[c] = '\0';
		if (!add_to_tr(&tr, buffer))
			break ;
	}
	if (c < 0)
		return (-1);
	*line = tr;
	return (add_to_leftover(&leftover[fd], buffer, c, ft_strlen(tr)));
}
