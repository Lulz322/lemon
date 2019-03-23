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

void	color_on(int id)
{
	if (id % 6 == 0)
		ft_printf("MRED(");
	else if (id % 6 == 1)
		ft_printf("MYLW(");
	else if (id % 6 == 2)
		ft_printf("MGRN(");
	else if (id % 6 == 3)
		ft_printf("MBLU(");
	else if (id % 6 == 4)
		ft_printf("MPRP(");
	else if (id % 6 == 5)
		ft_printf("MCYN(");
}

void	print_steps(t_ants *ants)
{
	while (ants)
	{
		if (g_global.color_mode)
			color_on(ants->ant_id);
		ft_printf("L%d-%s ", ants->ant_id,
			ants->position->room->name);
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
	ft_putchar('\n');
}

void	print_pathes(t_ways *list)
{
	int		count;
	t_ways	*start;

	count = 1;
	if (!g_global.color_mode)
		ft_printf("\nChoosen Ways:)\n\n");
	else
		ft_printf("\nMBLU(Choosen MCYN(Ways:)\n\n");
	start = list;
	while (list)
	{
		if (g_global.color_mode)
		{
			if (count++ % 2 == 0)
				ft_printf("MGRN(");
			else
				ft_printf("MPRP(");
		}
		print_path(list->way);
		list = list->next;
	}
	ft_printf("MGRN()\n");
	list = start;
}

void	print_total_steps(int s_counter)
{
	if (g_global.color_mode)
		ft_printf("MYLW(\nTolal steps:) MGRN(%d)\n", s_counter);
	else
		ft_printf("Total steps: %d\n", s_counter);
}
