# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 10:58:25 by tbillon           #+#    #+#              #
#    Updated: 2021/02/01 12:45:34 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

HEADERS = ./includes

MLX = ./minilibx

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

all:		$(NAME)

re:			fclean all

.PHONY: 	all fclean clean re
