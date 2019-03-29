/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:34:59 by iruban            #+#    #+#             */
/*   Updated: 2019/03/27 14:35:00 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_ways	*create_list_of_way(t_rooms *way)
{
	t_ways *ways;

	_ERROR_MALLOC(ways = malloc(sizeof(t_ways)));
	ways->way = way;
	ways->next = NULL;
	return (ways);
}

void	create_ways(t_ways **list,
					t_rooms *way)
{
	t_ways *start;
	t_ways *wheee;

	wheee = *list;
	if (!wheee)
		wheee = create_list_of_way(way);
	else
	{
		start = wheee;
		while (wheee->next != NULL)
			wheee = wheee->next;
		wheee->next = create_list_of_way(way);
		wheee = start;
	}
	*list = wheee;
}

t_ants	*remove_ant_two(t_ants **ants)
{
	t_ants *tmp;
	t_ants *qqq;

	tmp = NULL;
	tmp = *ants;
	qqq = *ants;
	qqq = qqq->next;
	*ants = qqq;
	return (tmp);
}

void	remove_ant(t_ants *ant)
{
	t_ants *tmp;
	t_ants *start;

	tmp = NULL;
	if (g_global.c_ants == ant)
		tmp = remove_ant_two(&g_global.c_ants);
	else
	{
		start = g_global.c_ants;
		while (start->next)
		{
			if (start->next == ant)
			{
				tmp = start->next;
				start->next = start->next->next;
				break ;
			}
			start = start->next;
		}
	}
	free(tmp);
}

void	create_ant(t_rooms *room)
{
	t_ants *start;
	t_ants *whee;

	whee = g_global.c_ants;
	if (!whee)
		whee = create_list_of_ants(room);
	else
	{
		start = whee;
		while (start->next)
			start = start->next;
		start->next = create_list_of_ants(room);
		if (start->next)
			start->next->prev = start;
		if (start->next)
			start->next->prev = start;
	}
	g_global.c_ants = whee;
}
