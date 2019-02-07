//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"

void	find_room(t_rooms *rooms, t_links *links, int id, int counter)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while(rooms)
	{
		if (rooms->room_id == id)
		{
			if (counter < rooms->index || rooms->index == -1)
			{
				rooms->index = counter;
				rooms->index_check = true;
				if (rooms->mode != 2)
					set_indexes(rooms, links, id, ++counter);
				else
					break;
			}
		}
		rooms = rooms->next;
	}
}

void	set_indexes(t_rooms *rooms, t_links *links, int save_id, int set_index)
{
	while (links->prev)
		links = links->prev;
	while (links)
	{
		if (links->first_room_id == save_id)
			find_room(rooms,links, links->second_room_id, set_index);
		else if (links->second_room_id == save_id)
			find_room(rooms, links, links->first_room_id, set_index);
		links = links->next;
	}
}

void	add_index(t_rooms *rooms, t_links *links)
{
	int save_id;
	int set_index;

	set_index = 0;
	while (rooms->next)
	{
		if (rooms->mode == 1)
			break;
		rooms = rooms->next;
	}
	save_id = rooms->room_id;
	rooms->index = set_index++;
	set_indexes(rooms, links, save_id, set_index);
	print_data(rooms);

}

