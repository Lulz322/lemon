NAME = lem_in

CC = gcc
@CFLAGS = -Wall -Wextra -Werror -Ofast  

SRC = srcs/main.c srcs/get_next_line.c srcs/cvars.c srcs/list_func.c srcs/list_func_two.c srcs/find_way.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) libftprintf.a $(LIBFT) -o $(NAME)
	@echo "> $(GREEN)lem_in$(WHITE)"

dfd:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./lem_in"

re: fclean all

.PHONY: all fclean clean re test
