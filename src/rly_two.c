/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rly_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:02:37 by iruban            #+#    #+#             */
/*   Updated: 2019/03/23 13:02:38 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

bool		add_room_in_list(t_rooms_algo **rooms, char *str, int mode)
{
	int x;
	int y;
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] != ' ')
		i--;
	i++;
	x = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i--;
	i--;
	while (str[i] >= '0' && str[i] <= '9')
		i--;
	i++;
	y = ft_atoi(&str[i]);
	str[i - 1] = '\0';
	add_data(rooms, str, x, y);
	if (mode != 0)
		change_mode(*rooms, mode);
	return (x >= 0 && y >= 0 ? true : false);
}

void		set_id(t_rooms_algo *rooms, t_links **links,
			char *first_str, char *second_str)
{
	t_rooms_algo *first;
	t_rooms_algo *second;

	first = rooms;
	second = rooms;
	while (first && ft_strcmp(first_str, first->name))
		first = first->next;
	while (second && ft_strcmp(second_str, second->name))
		second = second->next;
	add_data_link(links, first->room_id, second->room_id);
}

bool		add_link_in_list(t_links **links,
			t_rooms_algo *rooms, char *str)
{
	char	*first_str;
	char	*second_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (!str[i] && !g_global_algo.counter)
	{
		g_global_algo.atns = ft_atoi(str);
		return (true);
	}
	else
	{
		second_str = strdup(&str[i + 1]);
		str[i] = '\0';
		first_str = strdup(str);
		set_id(rooms, links, first_str, second_str);
	}
	return (true);
}

bool		check_line(char *str, t_rooms_algo **rooms,
			t_links **links, int mode)
{
	int spaces;
	int i;

	spaces = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			spaces++;
	if (spaces >= 2)
		_ERROR_NOTIS_ROOM(add_room_in_list(rooms, str, mode));
	if (spaces == 1)
		_ERROR_MSG;
	if (spaces == 0)
		_ERROR_NOTIS_LINK(add_link_in_list(links, *rooms, str));
	return (true);
}

bool		set_rooms_and_links(t_rooms_algo **rooms, t_links **links)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		while (1)
		{
			get_next_line(0, &line);
			if (!line || !ft_strcmp(line, ""))
				return (true);
			if (line[0] == '#')
			{
				if (i == 0)
					i = check_comment(line);
				free(line);
				break ;
			}
			_ERROR_NOTIS_LINE(check_line(line, rooms, links, i));
			i = 0;
		}
	}
}
