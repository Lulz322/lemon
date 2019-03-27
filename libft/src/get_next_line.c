/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:42:59 by iruban            #+#    #+#             */
/*   Updated: 2019/03/23 13:43:01 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check(char **s, int fd, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (i == 0)
		(*line) = ft_strdup("");
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
}

int		readlfile(int ret, char *buf, char **s, int fd)
{
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 0;
	ret = readlfile(ret, buf, s, fd);
	if (ret == -1)
		return (-1);
	if (s[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	if ((ret == 0 && s[fd][0] == '\0'))
	{
		*line = NULL;
		return (0);
	}
	check(s, fd, line);
	return (1);
}
