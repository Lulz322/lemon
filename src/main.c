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

void			errrorrororo(void)
{
	ft_printf("MGRN(Usage: ./lem-in [-c][-w][-s][-n][-a] < map)\n");
	ft_printf("\tMRED(-c)\tMRED(coMGRN(loMYLW(rs)\n");
	ft_printf("\tMRED(-w)\tMBLU(Print MPRP(ways)\n");
	ft_printf("\tMRED(-s)\tMYLW(Number of) MBLU(steps)\n");
	ft_printf("\tMRED(-n)\t ̶D̶o̶ ̶n̶o̶t̶ ̶p̶r̶i̶n̶t̶ ̶i̶n̶p̶u̶t ̶d̶a̶t̶a̶\n");
	ft_printf("\tMRED(-a)\tMPRP(All MBLU(data)\n");
	ft_printf("\t  \tMRED(DOES NOT WORKING W/ OTHER)\n");
}

void			parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-c"))
			g_global.color_mode = true;
		else if (ft_strequ(argv[i], "-w"))
			g_global.print_pathes = true;
		else if (ft_strequ(argv[i], "-s"))
			g_global.print_steps = true;
		else if (ft_strequ(argv[i], "-n"))
			g_global.non_print = true;
		else if (ft_strequ(argv[i], "-a"))
			g_global.second_algo = true;
		else
		{
			errrorrororo();
			exit(0);
		}
	}
}

int				main(int argc, char **argv)
{
	parsing_argc(argc, argv);
	if (g_global.second_algo == true)
		ta_nu_ladno();
	set_cvars(0, 0);
	check_first_last_room();
	_KOSTIL(kostil());
	first_algo();
	second_algo();
	if (set_eff(g_global.no_link_way) <= set_eff(g_global.link_way))
		pustit_jukov(g_global.no_link_way);
	else
		pustit_jukov(g_global.link_way);
	exit(0);
}
