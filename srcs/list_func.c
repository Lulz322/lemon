//
// Created by Ihor RUBAN on 2019-01-28.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"


void    change_mode(t_rooms *qwe,int mode)
{
    while (qwe->next)
        qwe = qwe->next;
    qwe->mode = mode;
}


t_rooms  *create_elem(char *data, int x, int y)
{
    t_rooms *new;

    new = (t_rooms *)malloc(sizeof(t_rooms));
    new->name = ft_strdup(data);
    new->link = false;
    new->mode = 0;
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

    new = *start;
    if (*start)
    {
        while (new->next)
            new = new->next;
        new->next = create_elem(data, x, y);
        new->next->prev = new;

    }
    else
        *start = create_elem(data, x , y);
}

void print_data(t_rooms *begin)
{
    while (begin->prev)
        begin = begin->prev;
    while (begin)
    {
        ft_printf("MRED(%s (%d)) MGRN(%d %d   MODE : %d) MBLU(Link w/ %d\n", begin->name,begin->room_id, begin->x_coord, begin->y_coord, begin->mode, begin->link_with_id);
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