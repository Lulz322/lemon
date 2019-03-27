/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:07:02 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 15:23:35 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*fresh;
	int			counter;

	if (s != NULL && f != NULL)
	{
		fresh = ft_strnew(ft_strlen(s));
		if (fresh == NULL)
			return (NULL);
		counter = 0;
		while (s[counter])
		{
			fresh[counter] = (*f)(s[counter]);
			counter++;
		}
		return (fresh);
	}
	return (NULL);
}
