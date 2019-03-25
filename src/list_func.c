/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:58:45 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:58:47 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room				*create_elem_room(char *line)
{
	char	**array;
	t_room	*new;

	array = ft_strsplit(line, ' ');
	check_errors_in_room(line, array);
	_ERROR_MALLOC(new = malloc(sizeof(t_room)));
	new->name = ft_strdup(array[0]);
	new->is_used = false;
	new->is_in_queue = false;
	new->x = ft_atoi(array[1]);
	new->y = ft_atoi(array[2]);
	new->links = NULL;
	free_array(array);
	return (new);
}

t_rooms				*create_list_of_rooms(t_room *first_room)
{
	t_rooms *way;

	_ERROR_MALLOC(way = malloc(sizeof(t_rooms)));
	way->room = first_room;
	way->prev = NULL;
	way->next = NULL;
	return (way);
}

bool				error_case(t_rooms *new, t_room *room)
{
	while (new)
	{
		if (ft_strequ(new->room->name, room->name))
			return (false);
		new = new->next;
	}
	return (true);
}

bool				create_room(t_rooms **list, t_room *room)
{
	t_rooms	*start;
	t_rooms	*new;

	new = *list;
	if (!error_case(new, room))
		return (false);
	if (!new)
		new = create_list_of_rooms(room);
	else
	{
		start = new;
		while (start->next)
			start = start->next;
		_ERROR_MALLOC(start->next = malloc(sizeof(t_rooms)));
		if (start->next)
			start->next->prev = new;
		start->next->room = room;
		start->next->next = NULL;
	}
	*list = new;
	return (true);
}

void				add_room_in_queue(t_rooms **list,
										t_room *room)
{
	t_rooms	*start;

	if (*list == NULL)
		*list = create_list_of_rooms(room);
	else
	{
		start = *list;
		while (start->next != NULL)
			start = start->next;
		_ERROR_MALLOC(start->next = malloc(sizeof(t_rooms)));
		if (start->next)
			start->next->prev = start;
		start->next->room = room;
		start->next->next = NULL;
	}
}

void 				free_queue(t_rooms **way)
{
	t_rooms			*del_me;
	t_rooms			*pointer;

	pointer = *way;
	del_me = pointer;
	pointer = pointer->next;
	*way = pointer;
	free(del_me);
	del_me = NULL;
}

t_room				*set_room(t_rooms **way)
{
	t_rooms *poin;
	t_room *room;

	poin = *way;
	room = poin->room;
	return (room);
}

void				check_errors_in_room(char *line, char **array)
{
	char	*x;
	char	*y;

	if (line_count(array) != 3 || char_count(' ', line) != 2)
		ERROR("Room definition example: ROOM_NAME X_COORD Y_COORD");
	if (array[0][0] == 'L')
		ERROR("Forbidden first charchter'L'");
	if (array[0][0] == '#')
		ERROR("Forbidden first charchter '#'");
	if (char_count('-', array[0]) != 0)
		ERROR("Forbidden charchter '-'");
	x = ft_itoa(ft_atoi(array[1]));
	y = ft_itoa(ft_atoi(array[2]));
	if (!ft_strequ(x, array[1]) || !ft_strequ(y, array[2]))
		ERROR("Error in coords!");
	free(x);
	free(y);
}
