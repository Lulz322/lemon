//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"

void	set_way(t_rooms *rooms,int save_id, t_way *way, t_truba *truba);

void	find_rooms(t_rooms *rooms, int id, t_way *way, t_truba *truba)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while(rooms)
	{
		if (rooms->room_id == id && way->is_end == false)
		{
			add_data_way(&way, rooms->room_id, false);
			add_data_truba(&truba, rooms->room_id);
			if (rooms->mode != 1)
				set_way(rooms, --id, way, truba);
			if (rooms->mode == 1)
				way->is_end = true;
		}
		rooms = rooms->next;
	}

}

void	set_way(t_rooms *rooms,int save_id, t_way *way, t_truba *truba)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms)
	{
		if (rooms->index == save_id)
			find_rooms(rooms, rooms->index, way, truba);
		rooms = rooms->next;
	}

	while (way->prev)
		way = way->prev;
	while (way)
	{
		ft_printf("LEN : %d\n", way->len);
		way = way->next;
	}
}


void	find_way(t_rooms *rooms, t_links *links)
{
	t_way *way;
	t_truba *truba;

	way = NULL;
	truba = NULL;
	add_index(rooms, links);
	int save;
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms->next)
	{
		if (rooms->mode == 2)
			break;
		rooms = rooms->next;
	}
	save = rooms->index;
	while (rooms->prev)
		rooms = rooms->prev;
	set_way(rooms, save, way, truba);

}