//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
//#include "../includes/ft_printf.h"

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

int    check_first_room(t_way *way, int id)
{
	t_truba *qwe;
	int save;

	save = 0;
	qwe = way->list;
	while (qwe && qwe->room_id != id)
	{
		save = qwe->room_id;
		qwe = qwe->next;
	}
	return save;

}

bool    check_way(t_way *way, int id, int id_prev)
{
	t_truba *test;
	int save;

	if (!way->prev)
		return true;
	test = way->list;
	while (test)
	{
		if (test->room_id == id)
			return (false);
		test = test->next;
	}
	while (way->prev)
	{
		save = check_first_room(way, id_prev);
		way = way->prev;
		test = way->list;
		while (test->next && test->room_id != id_prev)
			test = test->next;
		if (test->next == NULL || test->prev->room_id != save)
			return true;
		if (test->next->room_id == id && test->room_id != save)
			return false;
	}
	return (true);
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
void	find_rooms(t_rooms *rooms, int id, t_way *way);

void	find_one_line(t_rooms *rooms, int save, t_way *way)
{
	t_truba *qwe;

	qwe = way->list;
	while (rooms->prev)
		rooms = rooms->prev;
	while (qwe->next)
		qwe = qwe->next;
	while (rooms && way->is_end == false)
	{
		if (check_rooms(rooms->room_id, save) && qwe->room_id != rooms->room_id && check_way(way, rooms->room_id, save) == true && rooms->mode != 2)
		{
			add_data_truba(&way->list, save);
			if (rooms->mode == 1)
			{
				way->is_end = true;
				add_data_truba(&way->list, rooms->room_id);
				return;
			}
			find_rooms(rooms, rooms->room_id, way);
		}
		rooms = rooms->next;
	}
}

void	find_rooms(t_rooms *rooms, int id, t_way *way)
{
	int a;
	int i;

	i = 0;
	a = check_connections(rooms->room_id, rooms);
	if (a == 2 || a == 1)
		find_one_line(rooms, id, way);
	else
	{
		a -= 2;
		while (i++ < a)
			clone(rooms->room_id, way);
		while (i--)
		{
			find_one_line(rooms, id, way);
			way = way->next;
		}
	}
}

int     find_mode(t_rooms *rooms)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms->next && rooms->mode != 1)
		rooms = rooms->next;
	return (rooms->room_id);
}

void	set_way(t_rooms *rooms, int save_id, t_way *way, int save)
{
	t_rooms *save_rooms;
	while (rooms->prev)
		rooms = rooms->prev;
	save_rooms = rooms;
	while (rooms)
	{
		if (check_rooms(save_id, rooms->room_id) && save_id != rooms->room_id)
		{
			add_data_way(&way, 0, false);
			while (way->next)
				way = way->next;
			add_data_truba(&way->list, save_id);
			find_rooms(rooms, rooms->room_id,way);
		}
		rooms = rooms->next;
	}
//
	//clean_list(way, find_mode(save_rooms));
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