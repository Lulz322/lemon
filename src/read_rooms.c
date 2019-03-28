/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:01:20 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:01:22 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_start(char *line)
{
	t_room	*room;

	CREATE(line);
	if (!create_room(&g_global.ways, room))
		ERROR("Similar room name");
	if (g_global.start != NULL)
		ERROR("More then one START room");
	g_global.start = room;
}

void	create_end(char *line)
{
	t_room	*room;

	CREATE(line);
	if (!create_room(&g_global.ways, room))
		ERROR("Similar room name");
	if (g_global.end != NULL)
		ERROR("More then one END room");
	g_global.end = room;
}

void	check_first_last_room(void)
{
	if (!g_global.start)
		ERROR("Where's start room O_o?");
	if (!g_global.end)
		ERROR("Where's end room O_o?");
	KOSTIL(kostil());
}

void	rooms_mode(char *line, int *mode, int i)
{
	t_room	*room;

	if (i == 1 && mode)
		create_start(line);
	else if (i == 2 && mode)
		create_end(line);
	else
	{
		CREATE(line);
		if (!create_room(&g_global.ways, room))
			ERROR("Similar room name");
	}
}
