/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:32:20 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 13:32:22 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_bounus(const char *format)
{
	if (format[g_i] == 'L')
	{
		g_cvars.length = "L";
		g_i++;
		return (1);
	}
	else if (format[g_i] == 'j')
	{
		g_cvars.length = "j";
		g_i++;
		return (1);
	}
	else if (format[g_i] == 'z')
	{
		g_cvars.length = "z";
		g_i++;
		return (1);
	}
	else if (format[g_i] == 'l')
	{
		g_cvars.length = "l";
		g_i++;
	}
	return (g_i);
}

t_cvars		check_flags(const char *format, va_list argptr)
{
	while ((format[g_i] == ' ' || format[g_i] == '+' || format[g_i] == '-'
			|| format[g_i] == '#' || format[g_i] == '0') && argptr)
	{
		if (format[g_i] == ' ')
			g_cvars.flag[0] = ' ';
		else if (format[g_i] == '+')
			g_cvars.flag[1] = '+';
		else if (format[g_i] == '0')
			g_cvars.flag[2] = '0';
		else if (format[g_i] == '-')
			g_cvars.flag[3] = '-';
		else if (format[g_i] == '#')
			g_cvars.flag[4] = '#';
		g_i++;
	}
	return (g_cvars);
}

void		check_width(const char *format, va_list argptr)
{
	char	str[255];
	int		j;

	*str = '\0';
	j = 0;
	while (format[g_i] >= '0' && format[g_i] <= '9' && argptr)
		str[j++] = format[g_i++];
	str[j] = '\0';
	g_cvars.width = ft_atoi(str);
}

void		check_prec(const char *format, va_list argptr)
{
	char	str[13];
	int		j;

	str[0] = '\0';
	j = 0;
	while (format[g_i] >= '0' && format[g_i] <= '9' && argptr)
		str[j++] = format[g_i++];
	str[j] = '\0';
	g_cvars.prec = ft_atoi(str);
}
