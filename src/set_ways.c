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

t_rooms		*set_way(void)
{
	t_rooms *way;
	t_room	*room;

	room = g_global.start;
	way = NULL;
	while (room)
	{
		add_room_in_queue(&way, room);
		room->is_used = true;
		room = room->prev_room;
	}
	return (way);
}

t_rooms					*first_algo(void)
{
	t_rooms	*queue;
	t_room	*room;
	t_rooms *links;

	PREPARE(queue);
	while (queue)
	{
		DEL_AND_SET(&queue, room);
		if (room != g_global.start)
		{
			links = room->links;
			while (links)
			{
				if (!links->room->is_in_queue && !links->room->is_used)
					_F_IF_YO(&queue, links->room);
				links = links->next;
			}
		}
		else
			DEL(queue);
	}
	return (NULL);
}

t_rooms	*second_algo(void)
{
	t_rooms	*queue;
	t_room	*room;
	t_rooms *links;
	bool	is_pushed;

	PREPARE(queue);
	while (queue)
	{
		is_pushed = false;
		DEL_AND_SET(&queue, room);
		if (room != g_global.start)
		{
			links = room->links;
			while (links)
			{
				if (!links->room->is_in_queue && !links->room->is_used)
					_F_IF(links->next, is_pushed, &queue, links->room);
				links = links->next;
			}
		}
		else
			DEL(queue);
	}
	return (NULL);
}

bool		group_ways_two(void)
{
	t_rooms *tmp;

	CLEAR;
	_FIRST(tmp);
	if (!g_global.link_way)
		return (false);
	return (true);
}

bool		group_ways(void)
{
	t_rooms *tmp;

	CLEAR;
	_SECOND(tmp);
	if (!g_global.no_link_way)
		return (false);
	return (true);
}
