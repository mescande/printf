# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mescande <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 14:03:19 by mescande          #+#    #+#              #
#    Updated: 2020/02/19 14:34:51 by mescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

NAME = test
CC = gcc
#FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./
OBJ_DIR = obj/
INC_DIR = includes/
SRC_LIST = main.c\
		   ft_printf.c\
		   ft_atoi.c\
		   ft_gestionflags.c\
		   ft_putitin.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
DIR = $(sort $(dir $(OBJ)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "$(_BLUE)Compilation $(_GREEN)DONE !$(_WHITE)\r"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(DIR)
	@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)
	@echo -ne "$(_BLUE)Compilation... $(_WHITE)\r"

$(DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)
