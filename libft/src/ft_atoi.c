/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:50:43 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 14:50:44 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		int		skip_whitespaces(const char *str)
{
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) ||
			(str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r'))
		i++;
	return (i);
}

static		void	check_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
		*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

int					ft_atoi(const char *str)
{
	int		i;
	int		answer;
	int		sign;

	sign = 0;
	i = skip_whitespaces(str);
	answer = 0;
	check_sign(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		if ((9223372036854775807 - answer) < (str[i] - 48))
		{
			if (sign)
				return (0);
			else
				return (-1);
		}
		answer = answer * 10 + str[i] - 48;
		i++;
	}
	if (sign)
		answer = -answer;
	return (answer);
}
