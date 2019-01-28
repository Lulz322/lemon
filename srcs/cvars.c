#include "../includes/lem_in.h"
#include "ft_printf.h"

bool	check_line(char *line, t_rooms **qwe)
{
	int i;
	int counter;
	char *blyat;
	int y;


	blyat = ft_strnew(255);
	counter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			counter++;
		i++;
	}
	if (counter == 2)
	{
		i = 0;
		while (line[i] != ' ')
		{
			blyat[i] = line[i];
			i++;
		}
		blyat[i] = '\0';
		i++;
		counter = ft_atoi(&line[i]);
		while (line[i] != ' ')
			i++;
		i++;
		y = ft_atoi(&line[i]);
	}
	add_data(qwe, line, counter, y);
	return (true);
}

bool	set_cvars(void)
{
	char *line;
	char *all;
	int i;
	t_rooms *qwe;

	qwe = NULL;
	get_next_line(0, &line);
	g_global.atns = ft_atoi(line);
	free(line);
	while (1)
	{
		get_next_line(0, &line);
		check_line(line, &qwe);
		print_data(qwe);
		free(line);
		i++;
	}
	free(line);
	ft_printf("MGRN(%s)\n",all);
}
