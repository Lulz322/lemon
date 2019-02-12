//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"



t_truba  *create_elem_t_truba(int room_id)
{
	t_truba *new;

	new = (t_truba *)malloc(sizeof(t_truba));
	new->room_id = room_id;
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

void print_links_qwe(t_truba *begin)
{
	while (begin)
	{
		printf("%d - ", begin->room_id);
		begin = begin->next;
	}
	printf("\n");
}

void free_list_truba(t_truba *begin)
{
	t_truba *tmp;

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
	while (begin->prev)
		begin = begin->prev;
	while (begin)
	{
		start = begin->list;
		while (start->next)
			start = start->next;
		if (start->room_id == id)
			;
		else {
			//free_list_truba(begin->list);
			begin->prev->next = begin->next;
			//free(begin);
		}
		begin = begin->next;
	}
}