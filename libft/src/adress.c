/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:15:09 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 11:18:11 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*valid(char *str)
{
	int a;

	a = 0;
	while (str[a] != '0')
		a++;
	str[++a] = 'x';
	a++;
	while (str[a] != 'x' && str[a])
		a++;
	if (str[a] != '\0')
		str[a] = '0';
	return (str);
}

void	print_number_p(va_list argptr)
{
	void *number;
	char *str_s;

	number = va_arg(argptr, void *);
	str_s = print_address_hex(number, -13);
	if (g_cvars.prec != 0)
		g_cvars.prec += 2;
	if (g_cvars.prec)
		str_s = prec_helper(str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s);
	str_s = valid(str_s);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (number)
		free(str_s);
	clean();
}

void	print_percent(va_list argptr)
{
	char *str_s;

	if (!argptr)
		return ;
	str_s = ft_strdup("%\0");
	if (g_cvars.width)
		str_s = width_helper(str_s);
	print_number_h_s(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	ft_strdel(&str_s);
	clean();
}
