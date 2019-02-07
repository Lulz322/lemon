//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"


void	find_way(t_rooms *rooms, t_links *links)
{
	add_index(rooms, links);
	int save;
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms->next)
	{
		if (rooms->mode == 2)
			break;
		else
			rooms = rooms->next;
	}
	save = rooms->room_id;
	while (links->prev)
		links = links->prev;
	while (links->next);
}