/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:57 by iruban            #+#    #+#             */
/*   Updated: 2019/01/15 17:24:57 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*float_helper(char *str, long double f, long long value, int pos)
{
	char	*curr;
	int		len;

	len = pos - 1;
	while (pos < (len + g_cvars.prec + 7))
	{
		f = f - value;
		f *= 10;
		value = f;
		curr = ft_itoa(value);
		str[pos++] = *curr;
		free(curr);
	}
	str[len + g_cvars.prec + 7] = '\0';
	return (str);
}

char	*myfloat(long double f)
{
	char			*str;
	unsigned char	pos;
	char			len;
	long long		value;

	f = check_f(f);
	pos = 0;
	value = (long long)f;
	str = ft_itoa(value);
	if (ft_atoi(str) == 0 && g_cvars.prec == 0 && g_cvars.dot == '.')
		return (str);
	if (f < 0)
	{
		f *= -1;
		value *= -1;
	}
	len = ft_strlen(str);
	pos = len;
	str[pos++] = '.';
	return (float_helper(str, f, value, pos));
}

void	print_number_f(va_list argptr)
{
	char		*str_s;
	long double	yo;

	if (!ft_strcmp(g_cvars.length, "L"))
		yo = va_arg(argptr, long double);
	else
		yo = va_arg(argptr, double);
	str_s = myfloat(yo);
	if (g_cvars.prec)
		str_s = prec_f(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	free(str_s);
	clean();
}

void	prec_f_helper(char *str, int j)
{
	if (!g_cvars.prec && g_cvars.dot == '.')
	{
		while (str[j] != '.')
			j++;
		str[j] = '\0';
	}
	if (g_cvars.flag[1] == '+')
		ft_putchar('+');
	if (g_cvars.flag[3] == '-')
	{
		if (ft_atoi(str) >= 0)
			ft_putchar(' ');
		else
			ft_putchar('-');
	}
}

char	*prec_f(char *str)
{
	int		j;
	int		z;
	char	*str_w;
	int		len;

	str_w = ft_strnew(g_cvars.prec + 1);
	j = 0;
	z = 0;
	len = 0;
	while (str[len++] != '.')
		;
	if (g_cvars.prec)
	{
		while (str[j])
			str_w[z++] = str[j++];
		while (z <= g_cvars.prec + len)
			str_w[z++] = '0';
		str_w[g_cvars.prec + len] = '\0';
	}
	prec_f_helper(str_w, j);
	free(str);
	return (str_w);
}
