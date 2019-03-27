/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_for_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:19:19 by iruban            #+#    #+#             */
/*   Updated: 2019/03/23 13:19:20 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms_algo	*create_elem(char *data, int x, int y)
{
	t_rooms_algo *new;

	_ERROR_MALLOC(new = (t_rooms_algo *)malloc(sizeof(t_rooms_algo)));
	new->name = ft_strdup(data);
	new->mode = 0;
	new->index = -1;
	new->room_id = g_room_id++;
	new->x_coord = x;
	new->y_coord = y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			add_data(t_rooms_algo **start, char *data, int x, int y)
{
	t_rooms_algo *new;

	new = create_elem(data, x, y);
	new->next = *start;
	if (new->next)
		new->next->prev = new;
	*start = new;
}

t_links			*create_elem_link(int x, int y)
{
	t_links	*new;

	_ERROR_MALLOC(new = (t_links *)malloc(sizeof(t_links)));
	new->first_room_id = x;
	new->second_room_id = y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			add_data_link(t_links **start, int x, int y)
{
	t_links *new;

	new = create_elem_link(x, y);
	new->next = *start;
	if (new->next)
		new->next->prev = new;
	*start = new;
}

void			print_data(t_rooms_algo *begin)
{
	while (begin->prev)
		begin = begin->prev;
	ft_printf("MGRN(ROOM_NAME [ROOM_ID]) MYLW(X_COORD: Y_COORD:\n");
	ft_printf("MGRN(MODE:\n1->start\n2->end\n0-simple\n");
	ft_printf("MRED(length to start)\n");
	while (begin)
	{
		ft_printf("MGRN(NAME: %s [%d]MGRN(MODE : %d ",
		begin->name, begin->room_id, begin->mode);
		ft_printf(" MYLW(X: %d Y: %d   ", begin->x_coord, begin->y_coord);
		ft_printf("MRED( INDEX : %d)\n", begin->index);
		begin = begin->next;
	}
	ft_printf("\n");
}
