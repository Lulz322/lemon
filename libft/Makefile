NAME    = libft.a

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = objs

INCLS   = $(INC_DIR)
SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Ofast

LFLAGS  = -I.
AR      = ar rcs
RLIB    = ranlib

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

all:	obj
		@make -j $(NAME)

obj:
		@mkdir -p $(OBJ_DIR)

start_grn:
	@echo "$(GREEN)"

$(NAME): start_grn $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo ""
		@echo "$(GREEN)$(NAME) created!$(WHITE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@echo -n '+'
		@$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INCLS)

clean:
		@rm -rf $(OBJS) $(OBJ_DIR)
		@echo "$(RED)TMP files removed!$(WHITE)"

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR)
		@echo "$(RED)$(NAME) removed$(WHITE)"

re:		fclean all


.PHONY: all clean fclean re
