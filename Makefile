# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrandria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/02/02 20:17:32 by nrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

SRC_PATH = src/

SRC_NAME = src/place_unplace.c 		\
					 src/solve.c map.c			\
					 src/gettetri.c					\
					 src/main_error.c				\

OBJ_PATH	=	obj/

INCLUDE 	= -Iinclude -Ilibft/include

LDFLAGS		=	-Llibft
LDLIBS 		= -lft

NAME 			= fillit

CC 				= clang
CFLAGS 		= -Wall -Wextra -Werror -O3

OBJ_NAME 	=	$(addsuffix .o, $(basename $(SRC_NAME)))

SRC 		=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ 		=	$(addprefix $(OBJ_PATH),$(notdir $(OBJ_NAME)))

VPATH		=	$(shell find $(SRC_PATH) -type d)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[33mProject compilation\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32mCompilation SUCCESS\033[0m"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@echo "\033[33m.o's cleaning\033[0m"
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
