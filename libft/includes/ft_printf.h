/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:06:06 by osamoile          #+#    #+#             */
/*   Updated: 2018/05/01 14:06:10 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "libft.h"
# include <locale.h>
# include <inttypes.h>

unsigned int	g_symbols;
int				g_i;

typedef struct	s_cvars
{
	char		dot;
	char		flag[5];
	char		symbol;
	int			width;
	char		*length;
	int			prec;
	int			color;
}				t_cvars;

/*
**  0 | ' '     1 | +    2 | 0     3 | -  4| #
*/
t_cvars g_cvars;
/*
** -------------------------- Colors Definition --------------------------------
*/
# define PF_RED	        "\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"


/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
int				ft_printf(const char *format, ...);
/*
** -------------------------- Parsing Functions --------------------------------
*/
int				check_symbol(char format);
void			parsing(const char *format, va_list argptr);
t_cvars			check_flags(const char *format, va_list argptr);
void			check_cvars(const char *format, va_list argptr);
void			check_width(const char *format, va_list argptr);
void			check_prec(const char *format, va_list argptr);
int				check_length(const char *format);
char			*width_helper(char *str);
char			*prec_helper(char *str_s);
void			clean();
char			*print_number_part_two_d(long long int b, char **a);
char			*print_number_part_one_d(long long int b, char **a);
char			*print_number_part_two_o(va_list argptr);
char			*print_number_part_one_o(va_list argptr);
char			*print_number_part_two_x(unsigned long long b, char *a);
char			*print_number_part_one_x(unsigned long long b, char *a);
void			print_number(va_list argptr);
void			print_number_h(char *str);
void			print_number_h_o(char *str);
void			print_number_h_s(char *str);
void			print_x_h(char *str);
void			print_number_o(va_list argptr);
void			print_number_x(va_list argptr);
void			print_number_u(va_list argptr);
void			print_number_f(va_list argptr);
void			print_number_p(va_list argptr);
void			print_percent(va_list argptr);

/*
** -------------------------- Numbers Functions --------------------------------
*/
char			*prntnum_lower(unsigned long long n, char s,
				unsigned long long b);
char			*prntnum_upper(unsigned long long num, char sign, int base);
char			*print_address_hex(void *p0, int a);
char			*myfloat(long double fval);
char			*dcto(unsigned long long decimalnumber);
void			byte_to_binary(int x);
char			*prec_f(char *str);
long double		check_f(long double f);
char			hex_digit(int v);
char			*print_number_x_helper_two(char *str_s);
char			*print_number_x_helper_three(char *str, unsigned long long s);
char			*print_number_helper_three(char *str);
char			*print_number_hepler_two(char *str);
char			*print_number_helper_one(char *str, int i);
int				check_bounus(const char *format);
char			*print_x_j(char *str_s, unsigned long long sign);
/*
** ---------------------- Strings & Chars Functions ----------------------------
*/
void			print_string(va_list argptr);
void			print_char(va_list argptr);
/*
** --------------------------- Bonus Functions ---------------------------------
*/
void			color(const char *format);
void			color_help(const char *format);

#endif
