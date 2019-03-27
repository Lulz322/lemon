/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:12:47 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 15:13:11 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int len;

	len = ft_strlen(needle);
	if (len == 0)
		return (char *)haystack;
	while (*haystack)
		if (!ft_memcmp(haystack++, needle, len))
			return ((char *)haystack - 1);
	return (0);
}
