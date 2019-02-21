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
	while (begin)
	{
		ft_printf("%d - ", begin->room_id);
		begin = begin->next;
	}
	ft_printf("\n");
}

void free_list_truba(t_truba *begin)
{
	t_truba *tmp;

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
	t_way   *save;
	while (begin->prev)
		begin = begin->prev;
	save = begin;
	while (begin)
	{
		start = begin->list;
		while (start->next)
			start = start->next;
		if (start->room_id != id)
		{
			free_list_truba(begin->list);
			if (begin->prev)
				begin->prev->next = begin->next;
			free(begin);
			begin = save;
		}
		else
			begin = begin->next;
	}
}