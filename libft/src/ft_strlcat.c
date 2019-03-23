/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:31:09 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 15:30:23 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	char		*dest;
	const char	*sc;
	size_t		n;
	size_t		dlen;

	dest = dst;
	sc = src;
	n = dstsize;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dest++ = *sc;
			n--;
		}
		sc++;
	}
	*dest = '\0';
	return (dlen + (sc - src));
}
