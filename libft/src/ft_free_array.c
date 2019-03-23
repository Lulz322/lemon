/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:06:03 by iruban            #+#    #+#             */
/*   Updated: 2019/03/19 13:06:04 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char **line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		ft_strdel(&line[i]);
		i++;
	}
	free(line);
	line = NULL;
}
