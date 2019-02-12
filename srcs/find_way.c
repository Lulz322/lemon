//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"

bool    check_rooms(int index, int id)
{
	t_links *qwe;
	qwe = g_links;
	while (qwe->prev)
		qwe = qwe->prev;
	while (qwe)
	{
		if ((qwe->first_room_id == id && qwe->second_room_id == index) ||
				(qwe->second_room_id == id && qwe->first_room_id == index))
			return true;
		qwe = qwe->next;
	}
	return false;

}

void    check_first_room(t_way *way, t_rooms *rooms)
{
	int id;
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms)
	{
		if (rooms->mode == 2)
			id = rooms->room_id;
		rooms = rooms->next;
	}
	while (way->prev)
		way = way->prev;
	while (way)
	{
		if (way->list->room_id != id)
			add_data_truba_begin(&way->list, id);
		way =  way->next;
	}
}

void	set_way(t_rooms *rooms,int save_id, t_way *way,int save);

void    clone(int room_id, t_way *way)
{
	add_data_way(&way, 0, false);

	t_truba *qwe;
	qwe = way->list;
	while (way->next)
		way = way->next;
	while (qwe)
	{
		add_data_truba(&way->list, qwe->room_id);
		qwe = qwe->next;
	}
}

int 	check_connections(int id, t_rooms *rooms)
{
	int i;

	i = 0;
	t_links *qwe;
	qwe = g_links;

	while (qwe)
	{
		if (qwe->second_room_id == id || qwe->first_room_id == id)
			i++;
		qwe = qwe->next;
	}
	return (i);
}
void	find_rooms(t_rooms *rooms, int id, t_way *way, int save);

void	find_one_line(t_rooms *rooms, int save, t_way *way, int id)
{
	t_truba *qwe;

	qwe = way->list;
	while (rooms->prev)
		rooms = rooms->prev;
	while (qwe->next)
		qwe = qwe->next;
	while (rooms && way->is_end == false)
	{
		if ((rooms->index <= id) && check_rooms(rooms->room_id, save) && qwe->room_id != rooms->room_id)
		{
			add_data_truba(&way->list, save);
			if (rooms->mode == 1)
			{
				way->is_end = true;
				add_data_truba(&way->list, rooms->room_id);
				return;
			}
			find_rooms(rooms, rooms->room_id, way, id);
		}
		rooms = rooms->next;
	}
}

void	find_rooms(t_rooms *rooms, int id, t_way *way, int save)
{
	if ((check_connections(rooms->room_id, rooms) == 2 || check_connections(rooms->room_id, rooms) == 1))
		find_one_line(rooms, id, way, --save);
	else
		{
		clone(rooms->room_id, way);
		find_one_line(rooms, id, way, --save);
		way = way->next;
		find_one_line(rooms, id, way, --save);
	}
}

void	set_way(t_rooms *rooms, int save_id, t_way *way, int save)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms)
	{
		if (check_rooms(save_id, rooms->room_id) && save_id != rooms->room_id)
		{
			add_data_way(&way, 0, false);
			while (way->next)
				way = way->next;
			add_data_truba(&way->list, save_id);
			find_rooms(rooms, rooms->room_id,way, save);
		}
		rooms = rooms->next;
	}
	clean_list(way, 2);
	while (way->prev)
		way = way->prev;
	while (way)
	{
		print_links_qwe(way->list);
		way = way->next;
	}
}


void	find_way(t_rooms *rooms, t_links *links)
{
	t_way *way;
	int save2;

	way = NULL;
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
	save = rooms->room_id;
	save2 = rooms->index;
	while (rooms->prev)
		rooms = rooms->prev;
	set_way(rooms, save, way, save2);

}