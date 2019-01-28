cmake_minimum_required(VERSION 3.13)
project(lemon C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)
include_directories(printf)

add_executable(lemon
        includes/get_next_line.h
        includes/lem_in.h
        libft/includes/libft.h
        libft/ft_atoi.c
        libft/ft_isalpha.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strncat.c
        libft/ft_strncpy.c
        libft/ft_strnew.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_swap.c
        libft/lst_gnl.c
        printf/adress.c
        printf/check.c
        printf/check_two.c
        printf/float.c
        printf/ft_printf.c
        includes/ft_printf.h
        printf/hex.c
        printf/parser.c
        printf/prec.c
        printf/print_number.c
        printf/print_number_o_two.c
        printf/print_number_two.c
        printf/print_number_x_two.c
        printf/print_o.c
        printf/print_x.c
        printf/string.c
        srcs/get_next_line.c
        srcs/main.c srcs/cvars.c srcs/list_func.c)
