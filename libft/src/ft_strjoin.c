/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:09:48 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 15:09:52 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if (s1 && s2)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2) + 1))))
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp = ft_strcat(tmp, s2);
		return (tmp);
	}
	return (0);
}
