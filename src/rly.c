/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rly.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:51:38 by iruban            #+#    #+#             */
/*   Updated: 2019/03/23 12:51:45 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ta_nu_ladno(void)
{
	t_rooms_algo	*qwe;
	t_links			*za_sho;

	qwe = NULL;
	za_sho = NULL;
	g_room_id = 1;
	_ERROR_NOTIS_SET(set_rooms_and_links(&qwe, &za_sho));
	_ERROR_NOTIS_INDEX(set_indexes(za_sho, qwe));
	print_data(qwe);
	exit(0);
}

void		reset_used_rooms(void)
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		rooms->room->is_used = false;
		rooms = rooms->next;
	}
}

void		reset_rooms_in_queue(void)
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		rooms->room->is_in_queue = false;
		rooms->room->prev_room = NULL;
		rooms = rooms->next;
	}
	g_global.start->is_used = false;
	g_global.end->is_in_queue = true;
}
