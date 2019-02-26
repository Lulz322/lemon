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

int    check_last_room(t_truba *qwe)
{
	int save;

	save = 0;
	while (qwe)
	{
		save = qwe->room_id;
		qwe = qwe->next;
	}
	return save;

}


bool    check_prev_ways(t_truba *first, t_truba *save, int id, int next_room)
{
	while (first->prev)
		first = first->prev;
	while (save->prev)
		save = save->prev;
	while (first && save)
	{
		if (first->room_id != save->room_id)
			return true;
		save = save->next;
		first = first->next;
	}
	if (first && first->next && first->prev && (first->next->room_id == next_room || first->prev->room_id == next_room))
		return false;
	return  true;
}

bool    check_way(t_way *way, int id, int next_room)
{
	t_truba *qwe;
	t_way *save;
	int check;


	save = way;
	qwe = way->list;
	while (qwe)
	{
		if (next_room == qwe->room_id)
			return false;
		qwe = qwe->next;
	}
	way = save;
	return true;

}

void	set_way(t_rooms *rooms,int save_id, t_way *way,int save);

void    clone(t_way *way)
{

	add_data_way_next(&way, 0, false);
	t_truba *qwe;
	qwe = way->list;
	way = way->next;
	while (qwe)
	{
		add_data_truba(&way->list, qwe->room_id);
		qwe = qwe->next;
	}
	way = way->prev;
}

int     find_mode_start(t_rooms *rooms)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms->next && rooms->mode != 1)
		rooms = rooms->next;
	return (rooms->room_id);
}

int     find_mode_end(t_rooms *rooms)
{
	while (rooms->prev)
		rooms = rooms->prev;
	while (rooms->next && rooms->mode != 2)
		rooms = rooms->next;
	return (rooms->room_id);
}

int 	check_connections(int id, t_rooms *rooms)
{
	int i;

	i = 0;
	int end;

	end = find_mode_end(rooms);
	t_links *qwe;
	qwe = g_links;

	while (qwe)
	{
		if ((qwe->second_room_id == id || qwe->first_room_id == id) && end != id)
			i++;
		qwe = qwe->next;
	}
	return (i);
}
void	find_rooms(t_rooms *rooms, int id, t_way *way);


void	find_rooms(t_rooms *rooms, int id, t_way *way)
{
	int conn;
	int a;

	a = 0;
	conn = check_connections(id, rooms);
	if (conn == 2 || conn == 1 || find_mode_start(rooms) == id) {
		if (way->is_end != true)
			add_data_truba(&way->list, id);
		if (find_mode_start(rooms) == id)
			way->is_end = true;
	}
	else
	{
		conn -= 2;
		a = conn;
		while (a--)
		{
			clone(way);
			g_global.counter++;
		}
		while (a++ < conn)
		{
			if (way->is_end != true)
				add_data_truba(&way->list, id);
			way = way->next;
		}
	}

}

void    set_next_ways(t_rooms *rooms, t_way **qwe)
{
	int counter;
	int last_id;
	int d;
	t_rooms *save;
	t_way *way;
	save = rooms;
	way = *qwe;
	counter = g_global.counter;
	while (way->next)
		way = way->next;
	while (counter)
	{
		d = 0;
		rooms = save;
		last_id = check_last_room(way->list);
		while (rooms)
		{
			if (way->is_end == false &&check_rooms(rooms->room_id, last_id) && check_way(way, last_id, rooms->room_id))
			{
				d++;
				find_rooms(rooms, rooms->room_id, way);
				if (find_mode_start(rooms) == rooms->room_id) {
					way->is_end = true;
					g_global.counter--;
				}
				if (way->prev)
					way = way->prev;
				counter--;
				if (check_last_room(way->list) != last_id)
					break;
			}
			rooms = rooms->next;
		}
		if (d == 0 && way->is_end == false) {
            clean_list_one(&way);
            g_global.counter--;
            int a = g_global.counter;
            counter--;
        }
		else
		    {
                if (d == 0)
                    if (way->prev)
                        way = way->prev;
            }
	}
    *qwe = way;
}


void	set_way(t_rooms *rooms, int save_id, t_way *way, int save)
{
	t_way *save_q;
	g_global.counter = 0;
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
			g_global.counter++;
		}
		rooms = rooms->next;
	}
	rooms = save_rooms;
	int c;
	c = 0;
	while (rooms)
	{
		if (rooms->mode == 2) {
			c = rooms->index;
			break;
		}
		rooms = rooms->next;
	}
	c += 2;
	rooms = save_rooms;
	for (int i = 0; i <= c  ;i++) {
		set_next_ways(rooms, &way);
	}
	//clean_list(way, find_mode_start(save_rooms));
	while (way->prev)
		way = way->prev;
	while (way)
	{
		if (way->is_end == true)
			print_links_qwe(way->list);
		way = way->next;
	}
}


void	find_way(t_rooms *rooms, t_links *links)
{
	t_way *way;
	int save2;

	way = NULL;
	system("date");
	add_index(rooms, links);
	system("date");
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