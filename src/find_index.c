/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:38:39 by iruban            #+#    #+#             */
/*   Updated: 2019/03/23 11:38:41 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

bool	set_indexes(t_links *links, t_rooms_algo *rooms)
{
	t_rooms_algo	*start;
	int				room_id;
	int				set_index;

	set_index = 0;
	start = rooms;
	while (start->mode != 1)
		start = start->next;
	room_id = start->room_id;
	start->index = set_index++;
	check_room_for_index(&rooms, &links, room_id, set_index);
	return (true);
}

void	find_room(t_rooms_algo **start, t_links **links, int id, int counter)
{
	t_rooms_algo *rooms;

	rooms = *start;
	while (rooms)
	{
		if (rooms->room_id == id)
		{
			if (counter < rooms->index || rooms->index == -1)
			{
				rooms->index = counter;
				if (rooms->mode != 2)
					check_room_for_index(start, links, id, ++counter);
				else
					break ;
			}
		}
		rooms = rooms->next;
	}
}

void	check_room_for_index(t_rooms_algo **rooms, t_links **start,
							int save_id, int set_index)
{
	t_links *links;

	links = *start;
	while (links)
	{
		if (links->first_room_id == save_id && links->second_room_id != -1)
			find_room(rooms, start, links->second_room_id, set_index);
		else if (links->second_room_id == save_id && links->first_room_id != -1)
			find_room(rooms, start, links->first_room_id, set_index);
		links = links->next;
	}
}

int		line_count(char **line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
		i++;
	return (i);
}
