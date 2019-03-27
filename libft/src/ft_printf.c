/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:48:50 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 17:23:37 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		color_help(const char *format)
{
	if (format[g_i + 1] == 'B' && format[g_i + 2] == 'L' &&
	format[g_i + 3] == 'U' && format[g_i + 4] == '(')
		ft_putstr(PF_BLUE);
	if (format[g_i + 1] == 'P' && format[g_i + 2] == 'R' &&
	format[g_i + 3] == 'P' && format[g_i + 4] == '(')
		ft_putstr(PF_PURPLE);
	if (format[g_i + 1] == 'C' && format[g_i + 2] == 'Y' &&
	format[g_i + 3] == 'N' && format[g_i + 4] == '(')
		ft_putstr(PF_CYAN);
}

void		color(const char *format)
{
	if (format[g_i] == 'M' && format[g_i + 4] == '(')
	{
		if (format[g_i + 1] == 'R' && format[g_i + 2] == 'E' &&
				format[g_i + 3] == 'D' && format[g_i + 4] == '(')
			ft_putstr(PF_RED);
		if (format[g_i + 1] == 'G' && format[g_i + 2] == 'R' &&
				format[g_i + 3] == 'N' && format[g_i + 4] == '(')
			ft_putstr(PF_GREEN);
		if (format[g_i + 1] == 'Y' && format[g_i + 2] == 'L' &&
		format[g_i + 3] == 'W' && format[g_i + 4] == '(')
			ft_putstr(PF_YELLOW);
		color_help(format);
		g_i += 5;
		g_cvars.color = 1;
	}
	if (format[g_i] == ')' && g_cvars.color == 1)
	{
		ft_putstr(PF_EOC);
		if (!format[g_i + 1])
			exit(g_symbols);
		g_i++;
		g_cvars.color = 0;
	}
}

char		hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

long double	check_f(long double nbr)
{
	long double	f;
	int			n;

	if (g_cvars.prec > 0)
	{
		f = 0.5;
		n = 0;
		while (n++ < g_cvars.prec)
			f /= 10;
		if (nbr > 0)
			nbr += f;
		else if (nbr < 0)
			nbr -= f;
	}
	else
	{
		if (nbr < 0)
			nbr -= 0.0000005;
		else if (nbr > 0)
			nbr += 0.0000005;
	}
	return (nbr);
}

int			ft_printf(const char *format, ...)
{
	va_list argptr;

	g_symbols = 0;
	g_i = 0;
	va_start(argptr, format);
	while (format[g_i])
	{
		color(format);
		if (format[g_i] == '%')
			parsing(format, argptr);
		else
			ft_putchar(format[g_i]);
		if (format[g_i])
			g_i++;
	}
	va_end(argptr);
	clean();
	return (g_symbols);
}
