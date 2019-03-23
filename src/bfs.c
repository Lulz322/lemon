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

t_rooms		*create_way(t_room *room)
{
	t_rooms *way;

	way = NULL;
	while (room)
	{
		add_room_in_queue(&way, room);
		room->is_used = true;
		room = room->prev_room;
	}
	return (way);
}

void		reset_rooms_in_queue(t_rooms *room)
{
	while (room)
	{
		room->room->is_in_queue = false;
		room->room->prev_room = NULL;
		room = room->next;
	}
	g_global.start->is_used = false;
	g_global.end->is_in_queue = true;
}

t_rooms		*do_first_path(void)
{
	t_rooms	*queue;
	t_room	*room;

	PREPARE(queue);
	while (queue)
	{
		room = free_queue(&queue);
		if (room != g_global.start)
			first_algo_l(room->links, &queue, room);
		else
			DEL;
	}
	return (NULL);
}

t_rooms		*do_second_path(void)
{
	t_rooms	*queue;
	t_room	*room;

	PREPARE(queue);
	while (queue)
	{
		room = free_queue(&queue);
		if (room != g_global.start)
			second_algo_l(room->links, &queue, room);
		else
			DEL;
	}
	return (NULL);
}
