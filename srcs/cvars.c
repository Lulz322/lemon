#include "../includes/lem_in.h"
#include "ft_printf.h"

int		change_mode_line(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	if (!ft_strcmp(line, "##end"))
		return (2);
	free(line);
	return (0);
}

void	push_similar_room(char *line, t_rooms **qwe)
{
	char *blyat;
	int i;
	int y;
	int counter;

	i = 0;
	blyat = ft_strnew(255);
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
	add_data(qwe, blyat, counter, y);
	free(blyat);
}

void	find_and_place(char *str, char *str_two, t_rooms **qwe, t_links **whee)
{
	t_rooms *tmp;
	t_rooms *tmp_two;

	tmp = *qwe;
	tmp_two = *qwe;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp_two->prev)
		tmp_two = tmp_two->prev;
	while (ft_strcmp(tmp->name, str) && tmp->next)
		tmp = tmp->next;
	while (ft_strcmp(tmp_two->name, str_two) && tmp_two->next)
		tmp_two = tmp_two->next;
	add_data_link(whee, tmp->room_id, tmp_two->room_id);
	tmp->link = true;
	tmp_two->link = true;
}


void	push_links(char *line, t_rooms **qwe, t_links **za_sho)
{
	int i;
	char *str;
	char *str_two;
	int z;

	z = 0;
	i = 0;
	str = ft_strnew(255);
	str_two = ft_strnew(255);
	while (line[i] != '-')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	i++;
	while (line[i])
		str_two[z++] = line[i++];
	find_and_place(str, str_two, qwe, za_sho);
}



bool	check_line(char *line, t_rooms **qwe, int mode, t_links **za_sho)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	if (ft_strcmp(line, "") == 0)
		return (false);
	while (line[i])
	{
		if (line[i] == ' ')
			counter++;
		i++;
	}
	if (counter == 2)
		push_similar_room(line, qwe);
	if (mode != 0)
		change_mode(*qwe, mode);
	if (counter == 0)
		push_links(line, qwe, za_sho);
	return (true);
}

bool	set_cvars(void)
{
	char *line;
	int i;
	t_rooms *qwe;
	t_links *za_sho;

	qwe = NULL;
	za_sho = NULL;
	get_next_line(0, &line);
	g_global.atns = ft_atoi(line);
	free(line);
	while (1)
	{
		i = 0;
		get_next_line(0, &line);
		if (line[0] == '#')
		{
			i = change_mode_line(line);
			get_next_line(0, &line);
		}
		if (check_line(line, &qwe, i, &za_sho) == false)
			break;
		free(line);
	}
	free(line);
	print_data(qwe);
	print_links(za_sho);
}
