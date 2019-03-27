/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:01:07 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:01:08 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_ants(char *line, int *mode, int i)
{
	int		tmp;
	char	*str;

	tmp = 0;
	if (i != 0)
		ERROR("Ants can't be start/end room\nDude Rly?");
	tmp = ft_atoi(line);
	if (tmp <= 0)
		ERROR("ZERO Ants!");
	str = ft_itoa(tmp);
	if (ft_strequ(str, line))
		g_global.ants = ft_atoi(line);
	else
		ERROR("Trash in Ant linE!");
	free(str);
	*mode = 1;
}

int		check_comment(char *line)
{
	if (ft_strequ(line, "##start"))
		return (1);
	if (ft_strequ(line, "##end"))
		return (2);
	return (0);
}

void	check_line_aa(char *line)
{
	if (line[0] == 'L')
		ERROR("Forbidden first charchter'L'");
}

void	set_cvars_two(int *mode, int i, char *line)
{
	if (ft_strchr(line, '-') && char_count(' ', line) == 0
		&& char_count('-', line) == 1 && g_global.ants != 0)
		*mode = 2;
	check_line_aa(line);
	if (*mode == 0)
		set_ants(line, mode, i);
	else if (*mode == 1)
		rooms_mode(line, mode, i);
	else if (*mode == 2)
		create_link(line, i);
}

void	set_cvars(int mode, int i)
{
	char	*line;

	while (1)
	{
		while (1)
		{
			if (!input_data(&line))
				return ;
			else if (line[0] == '#')
			{
				if (i == 0)
					i = check_comment(line);
				ft_strdel(&line);
				break ;
			}
			set_cvars_two(&mode, i, line);
			free(line);
			i = 0;
		}
	}
}
