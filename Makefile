# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 10:58:25 by tbillon           #+#    #+#              #
#    Updated: 2021/02/04 13:09:34 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

HEADERS = ./includes

SRCS = ./srcs/*.c

UTILS = ./srcs/utils/*.c

ALL_SRCS = $(${SRCS}, ${UTILS})

OBJS = ${ALL_SRCS:.c=.o}

MLX = ./minilibx

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

all:		$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@make -s -C $(ALL_SRCS)
				@$(CC) $(CFLAGS) $(MLX) -I $(HEADER) $(OBJS) -o $(NAME)

norme:		
			norminettev2 $(SRCS) $(UTILS)

re:			fclean all

.PHONY: 	all fclean clean re
