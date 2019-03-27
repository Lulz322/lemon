/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:37:49 by iruban            #+#    #+#             */
/*   Updated: 2018/10/24 17:03:15 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int counter;

	counter = 1;
	if (nb <= 0)
		return (0);
	while (counter * counter < nb)
	{
		counter++;
	}
	if ((nb % counter) == 0)
		return (counter);
	else
		return (0);
}
