/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_o_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:36:43 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 13:36:44 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*print_number_part_two_o(va_list argptr)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "ll")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa(va_arg(argptr, unsigned long long));
		else
			str_s = dcto(va_arg(argptr, unsigned long long));
	}
	else if (!(ft_strcmp(g_cvars.length, "l")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa(va_arg(argptr, unsigned long));
		else
			str_s = dcto(va_arg(argptr, unsigned long));
	}
	if (!(ft_strcmp(g_cvars.length, "z")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa((va_arg(argptr, unsigned long long)));
		else
			str_s = dcto(va_arg(argptr, unsigned long long));
	}
	return (str_s);
}

char				*print_number_part_one_o(va_list argptr)
{
	char *str_s;

	if (!(ft_strcmp(g_cvars.length, "h")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa((unsigned short)va_arg(argptr, unsigned int));
		else
			str_s = dcto((unsigned short)va_arg(argptr, unsigned int));
	}
	if (!(ft_strcmp(g_cvars.length, "hh")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa((unsigned char)(va_arg(argptr, unsigned int)));
		else
			str_s = dcto((unsigned char)va_arg(argptr, unsigned int));
	}
	if (!(ft_strcmp(g_cvars.length, "j")))
	{
		if (g_cvars.symbol == 'u')
			str_s = ft_itoa((va_arg(argptr, intmax_t)));
		else
			str_s = dcto(va_arg(argptr, intmax_t));
	}
	return (str_s);
}

char				*print_number_h_o_helper_one(char *str)
{
	int i;

	i = 0;
	while (str[++i] == ' ')
		;
	if (ft_atoi(str) < 0 && !g_cvars.width)
		i--;
	while (str[i])
		ft_putchar(str[i++]);
	while (i-- > 0)
		if (str[i] == ' ')
			ft_putchar(str[i]);
	return (str);
}

char				*print_number_h_o_helper_two(char *str)
{
	int counter;

	counter = 0;
	if (g_cvars.width > g_cvars.prec)
	{
		while (str[counter] == ' ' || str[counter] == '0')
			counter++;
		str[counter - 1] = '0';
	}
	else
	{
		if (!g_cvars.width && !g_cvars.prec && ft_atoi(str) != 0)
			ft_putchar('0');
	}
	return (str);
}

void				print_number_h_o(char *str)
{
	int i;

	i = 0;
	if (g_cvars.flag[4] == '#')
		str = print_number_h_o_helper_two(str);
	if ((ft_atoi(str) > 0 && g_cvars.flag[1] == '+'))
	{
		if (g_cvars.prec > g_cvars.width)
			ft_putstr("+");
		while (str[i++] == ' ')
			;
		str[i - 2] = '+';
	}
	if (g_cvars.flag[3] == '-')
	{
		if (g_cvars.prec > g_cvars.width)
		{
			ft_putstr(str);
			return ;
		}
		str = print_number_h_o_helper_one(str);
	}
}
