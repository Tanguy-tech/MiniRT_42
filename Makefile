# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 10:58:25 by tbillon           #+#    #+#              #
#    Updated: 2021/02/02 15:31:34 by tbillon          ###   ########lyon.fr    #
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

re:			fclean all

.PHONY: 	all fclean clean re
