/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_x_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:36:48 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 13:36:50 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*print_number_part_two_x(unsigned long long sign, char *str_s)
{
	if (!(ft_strcmp(g_cvars.length, "ll")))
	{
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower(sign, ' ', 16);
		else
			str_s = prntnum_upper(sign, ' ', 16);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	else if (!(ft_strcmp(g_cvars.length, "l")))
	{
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned long int)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned long int)sign, ' ', 16);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	return (str_s);
}

char	*print_number_part_one_x(unsigned long long sign, char *str_s)
{
	if (!(ft_strcmp(g_cvars.length, "h")))
	{
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned short)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned short)sign, ' ', 16);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	if (!(ft_strcmp(g_cvars.length, "hh")))
	{
		if (g_cvars.symbol == 'x')
			str_s = prntnum_lower((unsigned char)sign, ' ', 16);
		else
			str_s = prntnum_upper((unsigned char)sign, ' ', 16);
		if (g_cvars.prec)
			str_s = prec_helper(str_s);
	}
	if (!(ft_strcmp(g_cvars.length, "j")))
		str_s = print_x_j(str_s, sign);
	return (str_s);
}

char	*print_x_helper(char *str)
{
	int i;

	i = 0;
	if (g_cvars.flag[4] == '#' && !g_cvars.width && !g_cvars.prec &&
		g_cvars.dot != '.' && g_cvars.symbol == 'X')
		ft_putstr("0X");
	if (g_cvars.flag[4] == '#' && !g_cvars.width && !g_cvars.prec &&
		g_cvars.dot != '.' && g_cvars.symbol == 'x')
		ft_putstr("0x");
	if (g_cvars.flag[4] == '#' && g_cvars.width >= (int)ft_strlen(str) &&
		g_cvars.flag[3] != '-' && !g_cvars.prec && g_cvars.dot != '.')
	{
		i = 2;
		while (str[i] == ' ')
			i++;
		str[i - 2] = '0';
		if (g_cvars.symbol == 'x')
			str[i - 1] = 'x';
		else
			str[i - 1] = 'X';
	}
	return (str);
}

char	*print_x_helper_two(char *str)
{
	int i;

	i = 0;
	while (str[++i] == ' ')
		;
	if (ft_atoi(str) < 0 && !g_cvars.width)
		i--;
	if (g_cvars.flag[4] == '#')
	{
		str[i - 2] = '0';
		if (g_cvars.symbol == 'x')
			str[i - 1] = 'x';
		else
			str[i - 1] = 'X';
		i = i - 2;
	}
	while (str[i])
		ft_putchar(str[i++]);
	while (i-- > 0)
		if (str[i] == ' ')
			ft_putchar(str[i]);
	return (str);
}

void	print_x_h(char *str)
{
	unsigned int i;

	i = 0;
	if ((ft_atoi(str) > 0 && g_cvars.flag[1] == '+'))
	{
		if (g_cvars.prec > g_cvars.width)
			ft_putstr("+");
		while (str[i++] == ' ')
			;
		str[i - 2] = '+';
	}
	str = print_x_helper(str);
	if (g_cvars.flag[3] == '-')
	{
		i = 0;
		if (g_cvars.prec > g_cvars.width)
		{
			ft_putstr(str);
			return ;
		}
		str = print_x_helper_two(str);
	}
}
