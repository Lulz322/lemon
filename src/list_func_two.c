/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:38 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:59:39 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	room_in_way(t_rooms *way, t_room *room)
{
	while (way)
	{
		if (way->room == room)
			return (true);
		way = way->next;
	}
	return (false);
}

t_room	*find_room_for_link(char *name)
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		if (ft_strequ(name, rooms->room->name))
			return (rooms->room);
		rooms = rooms->next;
	}
	return (NULL);
}

void	create_link(char *line, int i)
{
	char	**array;
	t_room	*first_room;
	t_room	*second_room;

	if (i != 0)
		ERROR("Link can't be Start/End Room!");
	array = ft_strsplit(line, '-');
	if (char_count(' ', line) != 0 || line_count(array) != 2)
		ERROR("ERROR");
	first_room = find_room_for_link(array[0]);
	second_room = find_room_for_link(array[1]);
	free_array(array);
	if (!first_room || !second_room)
		ERROR("Unknown room");
	if (first_room == second_room)
		ERROR("Simillar rooms");
	if (!room_in_way(first_room->links, second_room)
	&& !room_in_way(second_room->links, first_room))
	{
		add_room_in_queue(&first_room->links, second_room);
		add_room_in_queue(&second_room->links, first_room);
	}
	else
		ERROR("Link duplication");
}

int		set_eff(t_ways *list)
{
	int len;
	int ways;
	int length;

	ways = 0;
	len = 0;
	while (list)
	{
		len += way_len(list->way);
		ways++;
		list = list->next;
	}
	length = (g_global.ants + len) / ways - 1;
	if ((g_global.ants + len) % ways != 0)
		length += 1;
	return (length);
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
		return (false);
	}
	return (true);
}
