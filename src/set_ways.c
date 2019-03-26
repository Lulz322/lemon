/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:01:30 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:01:31 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reset_used_nodes()
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		rooms->room->is_used = false;
		rooms = rooms->next;
	}
}


void		del_room(t_rooms **list, t_room *node)
{
	t_rooms *tmp;
	t_rooms *start;
	t_rooms *pointer;

	tmp = NULL;
	pointer = *list;
	if (pointer->room == node)
	{
		tmp = pointer;
		pointer = pointer->next;
	}
	else
	{
		start = *list;
		while (pointer->next)
		{
			if (pointer->next->room == node)
			{
				tmp = pointer->next;
				pointer->next = pointer->next->next;
				break ;
			}
			pointer = pointer->next;
		}
		*list = start;
	}
	free(tmp);
}

bool	kostil(void)
{
	t_rooms *path;

	if (room_in_way(g_global.start->links, g_global.end))
	{
		path = NULL;
		add_room_in_queue(&path, g_global.start);
		add_room_in_queue(&path, g_global.end);
		create_ways(&g_global.no_link_way, path);
		del_room(&g_global.start->links, g_global.end);
		del_room(&g_global.end->links, g_global.start);
		return (false);
	}
	return (true);
}

void	first_algo()
{
	t_rooms *way;

	way = NULL;
	while ((way = begin_first()))
		create_ways(&g_global.no_link_way, way);
	if (!g_global.no_link_way)
		ERROR("ERROR")
}

void	second_algo(void)
{
	t_rooms *way;

	way = NULL;
	CLEAR
	while ((way = begin_second()))
		create_ways(&g_global.link_way, way);
	if (!g_global.link_way)
		ERROR("ERROR")
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