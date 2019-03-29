/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:23 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:59:25 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_way(t_rooms *way)
{
	t_rooms *start;

	start = way;
	if (way == NULL)
		return ;
	while (way->next)
	{
		while (way->next->next)
			way = way->next;
		free(way->next);
		way->next = NULL;
		way = start;
	}
	free(way);
}

int		way_len(t_rooms *list)
{
	int i;

	i = 0;
	while (list && ++i)
		list = list->next;
	return (i - 1);
}

int		char_count(char c, char *line)
{
	int i;
	int res;

	res = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == c)
			res++;
	}
	return (res);
}

void	free_array(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		ft_strdel(&line[i]);
		i++;
	}
	free(line);
	line = NULL;
}

void	change_mode(t_rooms_algo *qwe, int mode)
{
	qwe->mode = mode;
}
