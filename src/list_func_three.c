/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:23 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:59:25 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_way(t_rooms *way)
{
	t_rooms *start;

	start = way;
	if (way == NULL)
		return ;
	while (way->next)
	{
		while (way->next->next)
			way = way->next;
		free(way->next);
		way->next = NULL;
		way = start;
	}
	free(way);
}

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
		_ERROR_MALLOC(wheee->next = malloc(sizeof(t_ways)));
		wheee->next->way = way;
		wheee->next->next = NULL;
		wheee = start;
	}
	*list = wheee;
}

int		way_len(t_rooms *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i - 1);
}
