# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrandria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/11/06 01:54:36 by nrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

FLAGS = -Wall -Wextra -Werror -ansi -pedantic

HEAD = -Iincludes

SRC = src/ft_atoi.c						\
			src/ft_bzero.c					\
		 	src/ft_isalnum.c				\
			src/ft_isalpha.c				\
			src/ft_isascii.c				\
	  	src/ft_isdigit.c				\
			src/ft_isprint.c				\
			src/ft_memalloc.c				\
			src/ft_memccpy.c				\
			src/ft_memchr.c 				\
	  	src/ft_memcmp.c					\
			src/ft_memcpy.c 				\
			src/ft_memdel.c					\
			src/ft_memmove.c 				\
			src/ft_memset.c					\
	  	src/ft_putchar.c				\
			src/ft_putchar_fd.c 		\
			src/ft_putendl.c				\
			src/ft_putendl_fd.c			\
			src/ft_putnbr.c 				\
	  	src/ft_putnbr_fd.c			\
			src/ft_putstr.c					\
			src/ft_putstr_fd.c 			\
			src/ft_strcat.c					\
			src/ft_strchr.c				 	\
	  	src/ft_strclr.c 				\
			src/ft_strcmp.c					\
			src/ft_strcpy.c					\
			src/ft_strdel.c					\
			src/ft_strdup.c					\
	  	src/ft_strequ.c					\
			src/ft_striter.c				\
			src/ft_striteri.c				\
			src/ft_strjoin.c				\
			src/ft_strlcat.c			 	\
	  	src/ft_strlen.c 				\
			src/ft_strmap.c					\
			src/ft_strmapi.c				\
			src/ft_strncat.c				\
			src/ft_strncmp.c 				\
	  	src/ft_strncpy.c				\
			src/ft_strnequ.c				\
			src/ft_strnew.c					\
			src/ft_strnstr.c				\
			src/ft_strrchr.c				\
	  	src/ft_strstr.c 				\
			src/ft_strsub.c					\
			src/ft_strtrim.c				\
			src/ft_tolower.c				\
			src/ft_toupper.c 				\
	  	src/ft_strsplit.c				\
			src/ft_itoa.c						\
			src/ft_lstnew.c 				\
			src/ft_lstdelone.c 			\
			src/ft_lstdel.c 				\
	  	src/ft_lstadd.c					\
			src/ft_lstiter.c 				\
			src/ft_lstmap.c					\
			src/alpha_mirror.c 			\
			src/do_op.c 						\
			src/print_bits.c				\
			src/get_next_line.c			\
	  	src/ft_push_back.c 			\
			src/ft_push_front.c			\
			src/ft_create_elem.c 		\
			src/ft_abs.c						\

OBJ = $(SRC:src/%.c=%.o)

all: $(NAME)

$(NAME):
		@echo "\033[33m----------------------------------\033[0m"
		@echo "\033[36mCompiling in .o\033[0m"
		@$(CC) -c $(SRC) $(HEAD) $(FLAGS)
		@echo "\033[36mCreating library\033[0m"
		@ar rc $(NAME) $(OBJ)
		@echo "\033[36mIncrease the search speed\033[0m"
		@ranlib $(NAME)
		@echo "\033[32mLibrary Created\033[0m"
		@echo "\033[33m----------------------------------\033[0m"

clean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31mDeleting all .o\033[31m"
	@rm -rf $(OBJ)
	@echo "\033[32mThe folder is clean !\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

fclean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31mDeleting Library.a and all .o\033[31m"
	@rm -rf $(NAME) $(OBJ)
	@echo "\033[32mThe folder is clean\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
