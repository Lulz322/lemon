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

void				reset_used_rooms(void)
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		rooms->room->is_used = false;
		rooms = rooms->next;
	}
}

void				first_algo_l(t_rooms *links,
					t_rooms **queue, t_room *prev)
{
	while (links)
	{
		if (!links->room->is_in_queue && !links->room->is_used)
		{
			add_room_in_queue(queue, links->room);
			CHANGE;
		}
		links = links->next;
	}
}

void				second_algo_l(t_rooms *links,
					t_rooms **queue, t_room *prev)
{
	bool is_pushed;

	is_pushed = false;
	while (links)
	{
		if (!links->room->is_in_queue && !links->room->is_used)
		{
			if (!links->next || !is_pushed)
			{
				add_room_in_queue(queue, links->room);
				CHANGE;
				if (links->room->links->room != prev)
					is_pushed = true;
			}
		}
		links = links->next;
	}
}

void				first_algo(void)
{
	t_rooms *way;

	g_global.no_link_way = NULL;
	CLEAR;
	SECOND;
	if (!g_global.no_link_way)
		ERROR("ERROR");
}

void				second_algo(void)
{
	t_rooms *way;

	g_global.link_way = NULL;
	CLEAR;
	FIRST;
	if (!g_global.link_way)
		ERROR("ERROR");
}
