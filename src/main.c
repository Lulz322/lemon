/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:48 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 12:59:50 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			color_on(int id)
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

void			errrorrororo(void)
{
	ft_printf("MGRN(Usage: ./lem-in [-c][-w][-s][-n][-a] < map)\n");
	ft_printf("\tMRED(-c)\tMRED(coMGRN(loMYLW(rs)\n");
	ft_printf("\tMRED(-w)\tMBLU(Print MPRP(ways)\n");
	ft_printf("\tMRED(-s)\tMYLW(Number of) MBLU(steps)\n");
	ft_printf("\tMRED(-n)\t ̶D̶o̶ ̶n̶o̶t̶ ̶p̶r̶i̶n̶t̶ ̶i̶n̶p̶u̶t ̶d̶a̶t̶a̶\n");
	ft_printf("\tMRED(-a)\tMPRP(All MBLU(data)\n");
	ft_printf("\t  \tMRED(DOES NOT WORKING W/ OTHER)\n");
	exit(0);
}

bool			parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-c"))
			g_global.color_mode = true;
		else if (ft_strequ(argv[i], "-w"))
			g_global.print_ways = true;
		else if (ft_strequ(argv[i], "-s"))
			g_global.print_steps = true;
		else if (ft_strequ(argv[i], "-n"))
			g_global.non_print = true;
		else if (ft_strequ(argv[i], "-a"))
			g_global.second_algo = true;
		else
			return (false);
	}
	return (true);
}

int				input_data(char **line)
{
	int					gnl;
	static unsigned int counter;

	gnl = get_next_line(0, line);
	if (ft_strequ(*line, ""))
		ERROR("Empty Line");
	if (!g_global.non_print)
	{
		if (g_global.color_mode)
		{
			if (*line)
			{
				color_on(counter++);
				ft_printf("%s\n", *line);
			}
		}
		else
		{
			if (*line)
				ft_printf("%s\n", *line);
		}
	}
	return (gnl);
}

int				main(int argc, char **argv)
{
	_PARS(parsing_argc(argc, argv));
	_AFLAG;
	_SET_DATA(0, 0);
	_SET_FIRST_WAY;
	_SET_SECOND_WAY;
	_PRINT;
	_PRINT_T;
	exit(0);
}
