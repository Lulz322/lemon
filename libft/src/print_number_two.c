/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:35:34 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 13:35:35 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*print_number_part_two_d(long long b, char **str_s)
{
	if (!(ft_strcmp(g_cvars.length, "ll")))
	{
		*str_s = ft_itoa(b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	else if (!(ft_strcmp(g_cvars.length, "l")))
	{
		*str_s = ft_itoa((long)b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	if (!(ft_strcmp(g_cvars.length, "z")))
	{
		*str_s = ft_itoa(b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	return (*str_s);
}

char	*print_number_part_one_d(long long b, char **str_s)
{
	if (!(ft_strcmp(g_cvars.length, "h")))
	{
		*str_s = ft_itoa((short int)b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	if (!(ft_strcmp(g_cvars.length, "hh")))
	{
		*str_s = ft_itoa((signed char)b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	if (!(ft_strcmp(g_cvars.length, "j")))
	{
		*str_s = ft_itoa(b);
		if (g_cvars.prec)
			*str_s = prec_helper(*str_s);
	}
	return (*str_s);
}

char	*print_number_helper_one(char *str, int i)
{
	if (((g_cvars.width < (int)ft_strlen(str) && g_cvars.symbol != 'u'
		&& g_cvars.symbol != 'p') && ft_atoi(str) >= 0) ||
		((int)ft_strlen(str) < g_cvars.width && ft_atoi(str) >= 0))
		ft_putchar('+');
	if (g_cvars.width >= (int)ft_strlen(str) &&
		g_cvars.symbol != 'u' && ft_atoi(str) >= 0)
		str[0] = '+';
	if (g_cvars.width > g_cvars.prec && ft_atoi(str) >= 0)
	{
		if (str[0] == '+')
		{
			if (g_cvars.flag[2] == '0')
				str[0] = '0';
			else
				str[0] = ' ';
		}
		if ((int)ft_strlen(str) == g_cvars.width)
			i++;
		while (str[i++] == ' ')
			;
		str[i - 2] = '+';
	}
	return (str);
}

char	*print_number_hepler_two(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] == ' ')
		i++;
	if (ft_atoi(str) < 0 && !g_cvars.width)
		i--;
	if (str[0] == '+')
		ft_putchar('+');
	while (str[i])
		ft_putchar(str[i++]);
	while (i-- > 0)
		if (str[i] == ' ')
			ft_putchar(str[i]);
	return (str);
}

char	*print_number_helper_three(char *str)
{
	if (g_cvars.flag[1] != '+' && ft_atoi(str) > 0 &&
		g_cvars.symbol != 'u')
		if (g_cvars.prec >= g_cvars.width)
			ft_putchar(' ');
	if (g_cvars.width > g_cvars.prec && ft_atoi(str) >= 0
		&& g_cvars.flag[2] == '0')
		str[0] = ' ';
	return (str);
}
