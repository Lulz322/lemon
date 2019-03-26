/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:58:25 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:58:27 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					reset_rooms_in_queue()
{
	t_rooms *room;

	room = g_global.ways;
	while (room)
	{
		room->room->prev_room = NULL;
		room->room->is_in_queue = false;
		room = room->next;
	}
	g_global.start->is_used = false;
	g_global.end->is_in_queue = true;
}

void				work_with_links(t_rooms *links,
										   t_rooms **queue, t_room *prev)
{
	while (links)
	{
		if (!links->room->is_in_queue
			&& !links->room->is_used)
		{
			add_room_in_queue(queue, links->room);
			CHANGE
		}
		links = links->next;
	}
}

void				work_with_links_2(t_rooms *links,
											 t_rooms **queue, t_room *prev)
{
	bool is_pushed;

	is_pushed = false;
	while (links)
	{
		if (!links->room->is_in_queue
			&& !links->room->is_used)
		{
			if (!links->next || !is_pushed)
			{
				add_room_in_queue(queue, links->room);
				CHANGE
				if (links->room->links->room != prev)
					is_pushed = true;
			}
		}
		links = links->next;
	}
}



t_rooms			*begin_first(void)
{
	t_rooms *queue;
	t_room	*room;

	PREPARE(queue)
	while (queue)
	{
		DEL_AND_SET(&queue, room)
		if (room != g_global.start)
			work_with_links(room->links, &queue, room);
		else
			DEL(queue);
	}
	return (NULL);
}

t_rooms			*begin_second(void)
{
	t_rooms *queue;
	t_room	*room;

	PREPARE(queue)
	while (queue)
	{
		DEL_AND_SET(&queue, room)
		if (room != g_global.start)
			work_with_links_2(room->links, &queue, room);
		else
			DEL(queue);
	}
	return (NULL);
}


