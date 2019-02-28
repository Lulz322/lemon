//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
//#include "../includes/ft_printf.h"



t_truba  *create_elem_t_truba(int room_id)
{
	t_truba *new;

	new = (t_truba *)malloc(sizeof(t_truba));
	new->room_id = room_id;
	new->prev = NULL;
	new->next = NULL;
	return new;
}

t_truba  *create_elem_t_truba_begin(int room_id, t_truba *save)
{
	t_truba *new;

	new = (t_truba *)malloc(sizeof(t_truba));
	new->room_id = room_id;
	new->next = save;
	return new;
}

void add_data_truba_begin(t_truba **start, int x)
{
	t_truba *new;
	t_truba *save;

	save = *start;

	*start = create_elem_t_truba_begin(x, save);
}


void add_data_truba(t_truba **start, int x)
{
	t_truba *new;

	new = *start;
	if (*start)
	{
		while (new->next)
			new = new->next;
		new->next = create_elem_t_truba(x);
		new->next->prev = new;

	}
	else
		*start = create_elem_t_truba(x);
}


t_way  *create_elem_t_way(int len, bool	is_end)
{
	t_way *new;

	new = (t_way *)malloc(sizeof(t_way));
	new->len = len;
	new->list = NULL;
	new->is_end = is_end;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void add_data_way(t_way **start, int x, bool y)
{
	t_way *new;

	new = *start;
	if (*start)
	{
		while (new->next)
			new = new->next;
		new->next = create_elem_t_way(x, y);
		new->next->prev = new;

	}
	else
		*start = create_elem_t_way(x , y);
}
void    add_data_way_next(t_way **start, int x, bool y)
{
	t_way *new;
	t_way *tmp_next;
	t_way *tmp_prev;

	new = *start;
	tmp_next = NULL;

	if (new->next)
		tmp_next = new->next;
	new->next = create_elem_t_way(x, y);
	new->next->prev = new;
	if (tmp_next)
	{
		new->next->next = tmp_next;
		tmp_next->prev = new->next;
	}

}

void print_links_qwe(t_truba *begin)
{
	while (begin && begin->room_id)
	{
	    ft_putnbr(begin->room_id);
	    ft_putstr(" - ");
		//printf("%d - ", begin->room_id);
		begin = begin->next;
	}
	ft_putchar('\n');
}

void free_list_truba(t_truba **qwe)
{
	t_truba *tmp;
	t_truba *begin;

	begin = *qwe;
	tmp = begin;
	while (tmp->prev)
		tmp = tmp->prev;
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

void	clean_list(t_way *begin, int id)
{
	t_truba *start;
	t_truba *save_truba;
	t_way   *save;
	while (begin->prev)
		begin = begin->prev;
	while (begin)
	{
		start = begin->list;
		save_truba = begin->list;
		while (start->next)
			start = start->next;
		if (start->room_id != id)
		{
			free_list_truba(&save_truba);
			save = begin;
			if (begin->next)
				begin->next->prev = save->prev;
			if (begin->prev)
				if (begin->next)
					begin->prev->next = save->next;
		}
			begin = begin->next;
	}
}

void	clean_list_one(t_way **qwe)
{
    t_way *begin;
	t_truba *start;
	t_way *save;
	t_way *save_adr;

	begin = *qwe;
	start = begin->list;
	free_list_truba(&begin->list);
	//free(&begin->list);
	if (begin->prev)
		begin->prev->next = begin->next;
	if (begin->next)
		begin->next->prev = begin->prev;
	save = begin;
    if (!begin->prev) {
    	save_adr = save->next->next;
        free(save);
        *qwe = begin->next;
    }
    if (begin->prev) {
        *qwe = begin->prev;
        //begin = begin->prev;
        free(save);
        save = NULL;
    }

}

bool    check_other_ways(t_truba *qwe, int id)
{
    while (qwe)
    {
        if (qwe->room_id == id)
            return true;
        qwe = qwe->next;
    }
    return false;
}

void    del_other_ways(t_truba *qwe, t_way **way, t_rooms *rooms)
{
    t_way *yo;
    t_way *save;

    yo = *way;
    save = yo;
    while (qwe)
    {
        yo = save;
        *way = yo;
        while (yo)
        {
            if (yo->is_end == false)
            {
                if (qwe->room_id != g_global.last_room
                && qwe->room_id != g_global.first_room
                && check_other_ways(yo->list, qwe->room_id) == true) {
                    clean_list_one(way);
                    g_global.counter--;
                }
            }
            yo = yo->prev;
            *way = yo;
        }
        qwe = qwe->next;
    }
    *way = save;
}

void    del_one_room(t_rooms **rooms)
{
    t_rooms *qwe;

    qwe = *rooms;
    free(qwe->name);
    qwe->room_id = -1;
    if (qwe->next)
        qwe->next->prev = qwe->prev;
    if (qwe->prev)
        qwe->prev->next = qwe->next;
    if (!qwe->prev)
        *rooms = qwe->next;
    if (qwe->prev)
    {
        *rooms = qwe->prev;
    }
}

void    del_rooms(t_truba *qwe, t_rooms **rooms)
{
    t_rooms *save;
    t_rooms *iter;

    save = *rooms;
    iter = *rooms;
    while (qwe)
    {
        iter = save;
        *rooms = save;
        while (iter)
        {
            if (iter->room_id == qwe->room_id && iter->mode == 0)
            {
                del_one_room(rooms);
            }
            iter = iter->next;
            *rooms = iter;
        }
        qwe = qwe->next;
    }
}