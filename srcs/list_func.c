//
// Created by Ihor RUBAN on 2019-01-28.
//

#include "../includes/lem_in.h"
#include "../includes/ft_printf.h"


t_rooms  *create_elem(char *data, int x, int y)
{
    t_rooms *new;

    new = (t_rooms *)malloc(sizeof(t_rooms));
    new->name = ft_strdup(data);
    new->link = false;
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
        ft_printf("%s\n", begin->name);
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