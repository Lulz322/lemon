/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:08 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:59:10 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*create_list_of_ants(t_rooms *room)
{
	t_ants *ants;

	_ERROR_MALLOC(ants = malloc(sizeof(t_ants)));
	ants->ant_id = g_global.ant_counter;
	ants->position = room;
	ants->next = NULL;
	return (ants);
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

void	remove_ant(t_ants **ants, t_ants *ant)
{
	t_ants *tmp;
	t_ants *start;

	tmp = NULL;
	if (*ants == ant)
		tmp = remove_ant_two(ants);
	else
	{
		start = *ants;
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

void	create_ant(t_ants **ants, t_rooms *room)
{
	t_ants *start;
	t_ants *whee;

	whee = *ants;
	if (!whee)
		whee = create_list_of_ants(room);
	else
	{
		start = whee;
		while (start->next)
			start = start->next;
		_ERROR_MALLOC(start->next = malloc(sizeof(t_ants)));
		if (start->next)
			start->next->prev = start;
		start->next->ant_id = g_global.ant_counter;
		start->next->position = room;
		start->next->next = NULL;
	}
	*ants = whee;
}
