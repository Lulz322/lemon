/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:59:37 by iruban            #+#    #+#             */
/*   Updated: 2019/01/14 13:22:12 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*prntum_hepler(char *outbuf, char sign, int i)
{
	int j;

	j = 0;
	if (sign != ' ')
	{
		outbuf[0] = sign;
		++j;
	}
	while (++i < 17)
		outbuf[j++] = outbuf[i];
	outbuf[j] = 0;
	if (g_cvars.dot == '.' && g_cvars.prec == 0)
		outbuf = "\0";
	return (outbuf);
}

char	*prntnum_lower(unsigned long long num, char sign,
		unsigned long long base)
{
	int		i;
	char	*outbuf;

	if (ft_strcmp(g_cvars.length, "ll") == 0 ||
			ft_strcmp(g_cvars.length, "l") == 0 ||
			ft_strcmp(g_cvars.length, "j") == 0)
		i = 16;
	else
		i = 12;
	outbuf = ft_strnew(sizeof(char) * 255);
	outbuf[i] = "0123456789abcdef"[num % base];
	i--;
	num = num / base;
	while (num > 0)
	{
		outbuf[i] = "0123456789abcdef"[num % base];
		i--;
		num = num / base;
	}
	return (prntum_hepler(outbuf, sign, i));
}

char	*prntnum_upper(unsigned long long num, char sign, int base)
{
	int		i;
	char	*outbuf;

	if ((ft_strcmp(g_cvars.length, "ll") == 0 ||
				ft_strcmp(g_cvars.length, "l") == 0 ||
				ft_strcmp(g_cvars.length, "j") == 0) && num != 4294967296)
		i = 16;
	else
		i = 12;
	outbuf = ft_strnew(sizeof(char) * 255);
	outbuf[i] = "0123456789ABCDEF"[num % base];
	i--;
	num = num / base;
	while (num > 0)
	{
		outbuf[i] = "0123456789ABCDEF"[num % base];
		i--;
		num = num / base;
	}
	return (prntum_hepler(outbuf, sign, i));
}

char	*print_address_hex(void *p0, int counter)
{
	int			i;
	uintptr_t	p;
	char		*str;

	p = (uintptr_t)p0;
	counter = -13;
	str = (char *)malloc(sizeof(char) * 255);
	i = (sizeof(p) << 3) - 4;
	ft_strcat(str, "0x");
	if (p0 == NULL && g_cvars.dot != '.')
		return (ft_strcat(str, "0"));
	if (p0 == NULL)
		return (str);
	while (i >= 0)
	{
		if (counter == -13)
		{
			while (hex_digit((p >> i) & 0xf) == '0')
				i -= 4;
			counter = 2;
		}
		str[counter++] = hex_digit((p >> i) & 0xf);
		i -= 4;
	}
	return (str);
}

char	*dcto(unsigned	long long decimalnumber)
{
	unsigned long long	octalnumber;
	unsigned long long	i;
	unsigned long long	test;
	char				*str;

	octalnumber = 0;
	i = 1;
	test = 1844674407370955120;
	if (decimalnumber >= test && g_cvars.symbol != 'z')
		return (ft_strdup("1777777777777777777777"));
	if (decimalnumber >= test && g_cvars.symbol == 'z')
		return (ft_strdup("18446744073709551615"));
	while (decimalnumber != 0)
	{
		octalnumber += (decimalnumber % 8) * i;
		decimalnumber /= 8;
		i *= 10;
	}
	str = ft_itoa(octalnumber);
	return (str);
}
