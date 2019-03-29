/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:58:45 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:58:47 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool				error_case(t_rooms *new, t_room *room)
{
	while (new)
	{
		if (ft_strequ(new->room->name, room->name))
			return (false);
		new = new->next;
	}
	return (true);
}

void				free_queue(t_rooms **way)
{
	t_rooms			*del_me;
	t_rooms			*pointer;

	pointer = *way;
	del_me = pointer;
	pointer = pointer->next;
	*way = pointer;
	free(del_me);
	del_me = NULL;
}

t_room				*set_room(t_rooms **way)
{
	t_rooms	*poin;
	t_room	*room;

	poin = *way;
	room = poin->room;
	return (room);
}

bool				check_coords(int x, int y)
{
	t_rooms *rooms;

	rooms = g_global.ways;
	while (rooms)
	{
		if (rooms->room->x == x && rooms->room->y == y)
			return (false);
		rooms = rooms->next;
	}
	return (true);
}

void				check_errors_in_room(char *line, char **array)
{
	char	*x;
	char	*y;

	if (line_count(array) != 3 || char_count(' ', line) != 2)
		ERROR("Room ERROR \nexample: ROOM_NAME X_COORD Y_COORD");
	if (!check_coords(ft_atoi(array[1]), ft_atoi(array[2])))
		ERROR("Simmilar Coords!");
	x = ft_itoa(ft_atoi(array[1]));
	y = ft_itoa(ft_atoi(array[2]));
	if (!ft_strequ(x, array[1]) || !ft_strequ(y, array[2]))
		ERROR("Error in coords!");
	free(x);
	free(y);
}
