/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:09:59 by iruban            #+#    #+#             */
/*   Updated: 2018/10/27 15:10:03 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n)
{
	unsigned char *tmp;
	unsigned char *stmp;
	unsigned char ctmp;

	tmp = (unsigned char *)dst;
	stmp = (unsigned char *)src;
	ctmp = c;
	if (n)
	{
		while (n != 0)
		{
			if ((*tmp++ = *stmp++) == ctmp)
				return (tmp);
			--n;
		}
	}
	return (NULL);
}
