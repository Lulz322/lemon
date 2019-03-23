/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:51:53 by iruban            #+#    #+#             */
/*   Updated: 2018/10/30 16:23:59 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1,
		const char *restrict s2, size_t n)
{
	size_t	len;
	size_t	counter;

	len = ft_strlen(s1);
	counter = 0;
	while (s2[counter] && counter < n)
	{
		s1[len] = s2[counter];
		counter++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
