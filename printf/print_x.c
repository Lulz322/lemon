/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:19:50 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 15:19:51 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*print_x_j(char *str_s, unsigned long long sign)
{
	if (g_cvars.symbol == 'x')
		str_s = prntnum_lower((uintmax_t)sign, ' ', 16);
	else
		str_s = prntnum_upper((uintmax_t)sign, ' ', 16);
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	return (str_s);
}

char	*print_number_x_helper(char *str_s, uintmax_t sign)
{
	if (g_cvars.symbol == 'x')
		str_s = prntnum_lower(sign, ' ', 16);
	else
		str_s = prntnum_upper(sign, ' ', 16);
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	return (str_s);
}

char	*print_number_x_helper_two(char *str_s)
{
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_x_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	return (str_s);
}

char	*print_number_x_helper_three(char *str_s, unsigned long long sign)
{
	str_s = print_number_part_one_x(sign, str_s);
	str_s = print_number_part_two_x(sign, str_s);
	return (str_s);
}

void	print_number_x(va_list argptr)
{
	char				*str_s;
	unsigned long long	sign;

	if (!(ft_strcmp(g_cvars.length, "\0")))
		sign = va_arg(argptr, unsigned int);
	else
		sign = va_arg(argptr, unsigned long long);
	if (sign == 0 && !g_cvars.prec && !g_cvars.width && g_cvars.dot != '.')
	{
		ft_putchar('0');
		return ;
	}
	if (g_cvars.dot == '.' && g_cvars.prec == 0 && g_cvars.width == 0)
		str_s = ft_strdup("\0");
	if (ft_strcmp(g_cvars.length, "\0"))
		str_s = print_number_x_helper_three(str_s, sign);
	else
		str_s = print_number_x_helper(str_s, sign);
	str_s = print_number_x_helper_two(str_s);
	if (ft_strcmp(str_s, "\0"))
		free(str_s);
	clean();
}
