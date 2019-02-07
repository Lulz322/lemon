/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:52:27 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 14:52:30 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*print_number_o_hepler(char *str_s)
{
	if (ft_atoi(str_s) == 0 && g_cvars.width == 0 && g_cvars.prec == 0
		&& (g_cvars.dot != '.' || g_cvars.flag[4] == '#'))
		str_s = ft_strdup("0\0");
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	return (str_s);
}

unsigned long long	print_number_o_hhh(unsigned long long b)
{
	char *tmp;

	tmp = dcto(b);
	b = ft_atoi(tmp);
	if (tmp)
		free(tmp);
	return (b);
}

void				print_number_o(va_list argptr)
{
	unsigned long long	b;
	char				*str_s;

	if (!ft_strcmp(g_cvars.length, "\0"))
	{
		b = va_arg(argptr, unsigned int);
		b = print_number_o_hhh(b);
		if (g_cvars.dot == '.' && g_cvars.prec == 0 && b == 0)
			str_s = ft_strdup("");
		else
			str_s = ft_itoa(b);
	}
	else
	{
		str_s = print_number_part_one_o(argptr);
		str_s = print_number_part_two_o(argptr);
	}
	str_s = print_number_o_hepler(str_s);
	print_number_h_o(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
}

char				*print_number_u_helper(char *str_s)
{
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	return (str_s);
}

void				print_number_u(va_list argptr)
{
	long long	b;
	char		*str_s;

	if (!ft_strcmp(g_cvars.length, "\0"))
	{
		b = va_arg(argptr, unsigned int);
		if (g_cvars.dot == '.' && g_cvars.prec == 0 && b == 0)
			str_s = ft_strdup("");
		else
			str_s = ft_itoa(b);
	}
	else
	{
		str_s = print_number_part_one_o(argptr);
		str_s = print_number_part_two_o(argptr);
	}
	str_s = print_number_u_helper(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}
