/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pustit_jukov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:00:51 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:00:53 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	step(t_ants *ants)
{
	t_ants *buf;

	buf = ants;
	while (buf)
	{
		buf->position = buf->position->next;
		buf = buf->next;
	}
}

int		count_ways_sum(t_ways *start, t_ways *curr)
{
	int ways_sum;

	ways_sum = 0;
	while (start != curr)
	{
		ways_sum += way_len(curr->way) - way_len(start->way);
		start = start->next;
	}
	return (ways_sum);
}

void	new_ants(t_ants **ants, t_ways *pathes)
{
	t_ways	*start;

	start = pathes;
	while (pathes && g_global.ants - g_global.ant_counter != 0)
	{
		if (start->way->room == g_global.start &&
			start->way->next->room == g_global.end)
		{
			g_global.ant_counter++;
			create_ant(ants, pathes->way);
		}
		else
		{
			if (g_global.ants - g_global.ant_counter >
				count_ways_sum(start, pathes))
			{
				g_global.ant_counter++;
				create_ant(ants, pathes->way);
			}
			pathes = pathes->next;
		}
	}
	pathes = start;
}

void	remove_finishers(t_ants **ants)
{
	t_ants *tmp;

	tmp = *ants;
	while (tmp)
	{
		if (tmp->position->room == g_global.end)
			remove_ant(ants, tmp);
		tmp = tmp->next;
	}
}

void	pustit_jukov(t_ways *pathes)
{
	t_ants			*ants;
	int				s_counter;

	ants = NULL;
	g_global.ant_counter = 0;
	s_counter = 0;
	new_ants(&ants, pathes);
	while (ants)
	{
		step(ants);
		print_steps(ants);
		remove_finishers(&ants);
		new_ants(&ants, pathes);
		s_counter++;
	}
	if (g_global.print_pathes)
		print_pathes(pathes);
	if (g_global.print_steps)
		print_total_steps(s_counter);
}
