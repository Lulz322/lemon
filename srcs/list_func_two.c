//
// Created by Ihor RUBAN on 2019-02-07.
//

#include "../includes/lem_in.h"



t_truba  *create_elem_t_truba(int room_id)
{
	t_truba *new;

	new = (t_truba *)malloc(sizeof(t_truba));
	new->room_id = room_id;
	new->next = NULL;
	return new;
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
	new->len = 0;
	new->list = NULL;
	new->is_end = false;
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