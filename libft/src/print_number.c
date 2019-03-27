/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:20:28 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 14:30:46 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*print_number_helper_fore(char *str)
{
	int i;

	i = 0;
	if (g_cvars.flag[2] == '0')
	{
		if (g_cvars.width == (int)ft_strlen(str))
		{
			if (g_cvars.flag[3] != '-')
			{
				while (str[i] != '-' && str[i])
					i++;
			}
			str[i] = '0';
			str[0] = '-';
		}
	}
	return (str);
}

void	print_number_h(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '-' && str[i])
		;
	i--;
	if (str[i] == '-' && g_cvars.prec < g_cvars.width &&
			g_cvars.flag[3] != '-')
		str = print_number_helper_fore(str);
	if (g_cvars.flag[0] == ' ')
		print_number_helper_three(str);
	if (g_cvars.flag[1] == '+')
		str = print_number_helper_one(str, 0);
	if (g_cvars.flag[3] == '-')
	{
		if (g_cvars.prec > g_cvars.width)
		{
			ft_putstr(str);
			return ;
		}
		str = print_number_hepler_two(str);
	}
}

char	*print_number_hhh(char *str_s, long long number)
{
	if (g_cvars.dot == '.' && g_cvars.prec == 0 && number == 0)
		str_s = "\0";
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	return (str_s);
}

void	print_number(va_list argptr)
{
	long long	number;
	char		*str_s;

	str_s = NULL;
	if (ft_strcmp(g_cvars.length, "\0"))
		number = va_arg(argptr, long long);
	else
		number = va_arg(argptr, int);
	if (ft_strcmp(g_cvars.length, "\0"))
	{
		str_s = print_number_part_one_d(number, &str_s);
		str_s = print_number_part_two_d(number, &str_s);
	}
	else
	{
		str_s = ft_itoa(number);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	str_s = print_number_hhh(str_s, number);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}
