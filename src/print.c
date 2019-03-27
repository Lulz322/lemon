/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:00:06 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:00:09 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_steps(void)
{
	t_ants *ants;

	ants = g_global.c_ants;
	while (ants)
	{
		if (g_global.color_mode)
			color_on(ants->ant_id);
		ft_printf("L%d-%s ", ants->ant_id, ants->position->room->name);
		ants = ants->next;
	}
	ft_printf("\n");
}

void	print_path(t_rooms *way)
{
	while (way)
	{
		if (way->next)
			ft_printf("[%s]->", way->room->name);
		else
			ft_printf("[%s]", way->room->name);
		way = way->next;
	}
	ft_printf("\n");
}

void	print_pathes(t_ways *way)
{
	int		count;
	t_ways	*start;

	count = 1;
	if (!g_global.color_mode)
		ft_printf("\nChoosen Ways:)\n\n");
	else
		ft_printf("\nMBLU(Choosen MCYN(Ways:)\n\n");
	start = way;
	while (way)
	{
		if (g_global.color_mode)
			color_on(count++);
		print_path(way->way);
		way = way->next;
	}
	ft_printf("MGRN()\n");
	way = start;
}

void	print_total_steps(int s_counter)
{
	if (g_global.color_mode)
		ft_printf("MYLW(\nTolal steps:) MGRN(%d)\n", s_counter);
	else
		ft_printf("Total steps: %d\n", s_counter);
}
