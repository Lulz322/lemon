#include "../includes/lem_in.h"
#include "ft_printf.h"

bool	set_cvars(void)
{
	char *line;
	char *all;
	int i;

	all = (char *)malloc(sizeof(char) * 255);
	while (1)
	{
		get_next_line(0, &line);
		all = ft_strjoin(all, line);
		all = ft_strjoin(all, "\n");
		if (!ft_strcmp(line, ""))
			break;
		free(line);
	}
	free(line);
	ft_printf("MGRN(%s)\n",all);
}
