#include "../includes/lem_in.h"

int		check_comment(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (1);
	if (!ft_strcmp(str, "##end"))
		return (2);
	return (0);
}

bool	add_room_in_list(t_rooms **rooms)
{

}

bool	check_line(const char *str, t_rooms **rooms, t_links **links)
{
	int spaces;
	int i;

	spaces = 0;
	i = -1;
	while (str[++i])
		if(str[i] == ' ')
			spaces++;
	if(spaces >= 2)
		_ERROR_NOTIS_ROOM(add_room_in_list(rooms));

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