/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:35:16 by iruban            #+#    #+#             */
/*   Updated: 2019/03/27 14:35:17 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_ants				*create_list_of_ants(t_rooms *room)
{
	t_ants *ants;

	_ERROR_MALLOC(ants = malloc(sizeof(t_ants)));
	ants->ant_id = g_global.ant_counter;
	ants->position = room;
	ants->next = NULL;
	return (ants);
}

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

void				add_room_in_queue(t_rooms **list, t_room *room)
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
