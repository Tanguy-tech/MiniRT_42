# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 10:58:25 by tbillon           #+#    #+#              #
#    Updated: 2021/02/02 16:35:17 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

HEADERS = ./includes

SRCS = ./srcs/*.c

UTILS = ./srcs/utils/*.c

MLX = ./minilibx

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

all:		$(NAME)

norme:		
			norminettev2 $(SRCS) $(UTILS)

re:			fclean all

.PHONY: 	all fclean clean re
