/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pustit_jukov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:00:51 by iruban            #+#    #+#             */
/*   Updated: 2019/03/27 16:26:37 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				del_end_room(void)
{
	t_ants *tmp;

	tmp = g_global.c_ants;
	while (tmp)
	{
		if (tmp->position->room == g_global.end)
			remove_ant(tmp);
		tmp = tmp->next;
	}
}

void				one_step(void)
{
	t_ants *next;

	next = g_global.c_ants;
	while (next)
	{
		next->position = next->position->next;
		next = next->next;
	}
	print_steps();
	del_end_room();
}

unsigned int		all_count(t_ways *start, t_ways *curr)
{
	unsigned int ways_sum;

	ways_sum = 0;
	while (start != curr)
	{
		ways_sum += way_len(curr->way) - way_len(start->way);
		start = start->next;
	}
	return (ways_sum);
}

void				new_ants(t_ways *way)
{
	t_ways	*start;

	start = way;
	while (way && g_global.ant_counter != g_global.ants)
	{
		_S_T;
		_S_O(g_global.start, g_global.end);
		way = way->next;
	}
	way = start;
}

void				pustit_jukov(t_ways *way)
{
	int				s_counter;

	g_global.c_ants = NULL;
	g_global.ant_counter = 0;
	s_counter = 0;
	ft_printf("\n");
	new_ants(way);
	while (g_global.c_ants && ++s_counter)
		ANTS(way);
	if (g_global.print_pathes)
		print_pathes(way);
	if (g_global.print_steps)
		print_total_steps(s_counter);
}
