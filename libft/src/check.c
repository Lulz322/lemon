/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:18:32 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 11:49:32 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_length(const char *format)
{
	if (format[g_i] == 'h' && format[g_i + 1] == 'h')
	{
		g_cvars.length = "hh";
		g_i = g_i + 2;
	}
	else if (format[g_i] == 'l' && format[g_i + 1] == 'l')
	{
		g_cvars.length = "ll";
		g_i = g_i + 2;
	}
	else if (format[g_i] == 'h')
	{
		g_i++;
		g_cvars.length = "h";
	}
	else if (format[g_i] == 'L' || format[g_i] == 'j'
			|| format[g_i] == 'z' || format[g_i] == 'l')
		check_bounus(format);
	else
	{
		g_cvars.length = "\0";
		return (0);
	}
	return (1);
}

void		until_symbol(const char *format)
{
	const	char	*symbols = "%douxXipfcsZb";
	int				j;

	j = 0;
	while (format[g_i])
	{
		j = 0;
		while (symbols[j])
		{
			if (format[g_i] == symbols[j])
				return ;
			else
				j++;
		}
		g_i++;
	}
}

int			behaivor(const char *format)
{
	if (format[g_i] == 'h')
	{
		g_i++;
		return (0);
	}
	return (1);
}

void		check_cvars(const char *format, va_list argptr)
{
	if (format[g_i - 1] == '%' && ((format[g_i] == ' ' &&
	format[g_i + 1] == '\0') || format[g_i] == '\0'))
	{
		++g_i;
		return ;
	}
	check_flags(format, argptr);
	check_width(format, argptr);
	if (format[g_i] == '.')
	{
		while (format[++g_i] == '.')
			;
		g_cvars.dot = '.';
	}
	if (g_cvars.dot == '.')
		check_prec(format, argptr);
	check_length(format);
	until_symbol(format);
	if (format[g_i] == '\0')
		while (format[--g_i] == ' ')
			;
	if (behaivor(format) == 0)
		return ;
	check_symbol(format[g_i]);
}

int			check_symbol(char format)
{
	if (format)
		g_cvars.symbol = format;
	else
	{
		g_cvars.symbol = 0;
		return (0);
	}
	return (1);
}
