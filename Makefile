# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mescande <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 14:03:19 by mescande          #+#    #+#              #
#    Updated: 2020/03/09 15:17:16 by mescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_WHITE=$ \x1b[37m
_BLUE=$ \x1b[36m
_GREEN=$ \033[1;32m
_GREY=$ \x1b[33m
_RED=$ \x1b[31m

NAME = libftprintf.a
EXEC = test
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./
OBJ_DIR = obj/
INC_DIR = includes/
MAIN_LST = main.c
SRC_LIST = ft_printf.c\
		   ft_atoi.c\
		   ft_gestionflags.c\
		   ft_putitin.c\
		   ft_conv_1.c\
		   ft_conv_2.c\
		   ft_strlen.c\
		   ft_strdup.c\
		   ft_memcpy.c\
		   ft_itoa.c\
		   ft_strnew.c\
		   ft_bzero.c\
		   ft_memset.c\
		   ft_memalloc.c\
		   ft_strjoin.c\
		   ft_utoa_base.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
DIR = $(sort $(dir $(OBJ)))
MAIN = $(addprefix $(SRC_DIR), $(MAIN_LST:.c = .o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(_BLUE)Compilation $(_GREEN)DONE !$(_WHITE)\r"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(DIR)
	@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)
	@echo "$(_BLUE)Compilation... $(_WHITE)\r"

$(DIR):
	@mkdir -p $@

$(EXEC): $(OBJ) $(MAIN)
	@$(CC) $^ -o $@
	@echo "$(_BLUE)Compilation $(_GREEN)DONE !$(_WHITE)\r"

clean:
	@rm -rf $(OBJ_DIR)

aclean: clean
	@rm -rf $(EXEC)
	@rm -rf $(NAME)

tclean: clean
	@rm -rf $(EXEC)

fclean: clean
	@rm -rf $(NAME)

re: aclean
	@$(MAKE)

.PHONY: all clean aclean tclean fclean re

-include $(OBJ:.o=.d)
