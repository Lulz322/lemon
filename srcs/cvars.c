#include "../includes/lem_in.h"

int		check_comment(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (1);
	if (!ft_strcmp(str, "##end"))
		return (2);
	return (0);
}

bool	add_room_in_list(t_rooms **rooms, char *str)
{
	int x;
	int y;
	int i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != ' ')
		i--;
	i++;
	x = (int)ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i--;
	i--;
	while (str[i] >= '0' && str[i] <= '9')
		i--;
	i++;
	y = (int)ft_atoi(&str[i]);
	str[i - 1] = '\0';
	add_data(rooms, str, x, y);
	return (x && y ? true : false);
}

bool	check_line(char *str, t_rooms **rooms, t_links **links)
{
	int spaces;
	int i;

	spaces = 0;
	i = -1;
	while (str[++i])
		if(str[i] == ' ')
			spaces++;
	if(spaces >= 2)
		_ERROR_NOTIS_ROOM(add_room_in_list(rooms,str));
	return true;
}

bool	set_rooms_and_links(t_rooms **rooms, t_links **links)
{
	int i;
	char *line;

	i = 0;
	while (1)
	{
		while (1)
		{
			if (get_next_line(0, &line) == 0)
				return (true);
			if (line[0] == '#')
			{
				if (i == 0)
					i = check_comment(line);
				free(line);
				break;
			}
			_ERROR_NOTIS_LINE(check_line(line, rooms, links));
			i = 0;
		}
	}
}