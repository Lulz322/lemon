#include "../includes/lem_in.h"
//#include "../includes/ft_printf.h"


void    change_mode(t_rooms *qwe,int mode)
{
    while (qwe->next)
        qwe = qwe->next;
    qwe->mode = mode;
}


t_rooms  *create_elem(char *data, int x, int y)
{
	t_rooms *new;

	_ERROR_MALLOC(new = (t_rooms *)malloc(sizeof(t_rooms)));
	new->name = ft_strdup(data);
	new->mode = 0;
	new->index = -1;
	new->room_id = g_room_id++;
	new->x_coord = x;
	new->y_coord = y;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void add_data(t_rooms **start, char *data, int x, int y)
{
	t_rooms *new;

	new = create_elem(data, x , y);
	new->next = *start;
	if (new->next)
		new->next->prev = new;
	*start = new;
}

t_links  *create_elem_link(int x, int y)
{
	t_links	 *new;

	new = (t_links *)malloc(sizeof(t_links));
	new->first_room_id = x;
	new->second_room_id = y;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void add_data_link(t_links **start, int x, int y)
{
	t_links *new;

	new = create_elem_link(x , y);
	new->next = *start;
	*start = new;
}

void print_links(t_links *begin)
{
	while (begin->prev)
		begin = begin->prev;
	while (begin)
	{
		ft_printf("MBLU(ROOM ID: %d LINKS w/ ID : %d)\n", begin->first_room_id, begin->second_room_id);
		begin = begin->next;
	}
	ft_printf("\n");
}

void print_data(t_rooms *begin)
{
    while (begin->prev)
        begin = begin->prev;
    while (begin)
    {
        ft_printf("MRED(%s (%d)) MGRN(%d %d   MODE : %d) MRED( INDEX : %d)\n", begin->name,begin->room_id, begin->x_coord, begin->y_coord, begin->mode, begin->index);
        begin = begin->next;
    }
    ft_printf("\n");
}

void free_list(t_rooms *begin)
{
    t_rooms *tmp;

    while (begin)
    {
        tmp = begin->next;
        free(begin);
        begin = tmp;
    }
}