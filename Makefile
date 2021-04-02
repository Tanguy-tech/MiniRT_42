# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 10:58:25 by tbillon           #+#    #+#              #
#    Updated: 2021/04/02 13:58:17 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE       =   \033[2K\r
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

NAME = miniRT

HEADERS = colors.h element.h image.h minirt.h res.h resolve.h scenes.h \
utils.h vectors.h

SRCS = check_common_format.c parse_common_data.c ray.c \
scenes.c square.c vectors_operators.c check_format_engine.c errors.c \
plan.c raytracing.c sphere.c square_intersection.c vectors.c window.c \
cylinder.c mini_rt.c plan_intersection.c read_and_parse.c \
sphere_intersection.c triangle.c vectors_operator_bis.c \
triangle_intersection.c

UTILS = check_coord.c count_array.c ft_abs.c \
ft_calloc.c ft_iswhitespace.c ft_lst_new.c ft_putnbr.c ft_str_add_char.c \
ft_strnstr.c ft_substr.c get_next_line.c valid_format.c check_intensity.c \
count_double.c ft_atof.c ft_isalpha.c ft_lst_add_back.c ft_memcpy.c ft_putstr.c\
ft_strlen.c ft_strrchr.c get_angle.c size_num.c check_range.c count_rgb_format.c\
ft_atoi.c ft_isdigit.c ft_lst_add_front.c ft_putchar.c ft_split.c ft_strncmp.c \
ft_strtod.c get_double.c to_find.c

OBJS_HEADERS = $(addprefix ./includes/, $(HEADERS))

OBJS_SRCS = $(addprefix ./srcs/, $(SRCS:.c=.o))

OBJS_UTILS = $(addprefix ./srcs/utils/, $(UTILS:.c=.o))

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

$(NAME):		$(OBJS_SRCS) $(OBJS_UTILS)
					@printf "$(ERASE)$(GREEN)-> Files .o Created with success$(END)\n"
					@make -C ./minilibx
					@mv ./minilibx/libmlx.dylib .
					@$(CC) $(FLAGS) $(OBJS_SRCS) $(OBJS_UTILS) -I $(OBJS_HEADERS) libmlx.dylib
					@mv a.out miniRT
					@printf "$(CYAN)-> Executable file miniRT Created with success!\n$(BLUE)You can execute $(YELLOW)./miniRT$(BLUE) with the $(YELLOW)scene$(BLUE) of your choise$(END)\n"

all:		$(NAME)

%.o: %.c $(OBJS_HEADERS)
		 @$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./includes
		 @printf "$(ERASE)$(YELLOW)$<....$(END)"

norme:		
			norminette $(addprefix ./srcs/, $(SRCS))
			norminette $(addprefix ./srcs/utils/, $(UTILS))

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) ./includes/*.gch
			@$(RM) libmlx.dylib
			@make clean -C ./minilibx
			@$(RM) a.out.dSYM
			@$(RM) $(OBJS_SRCS)
			@$(RM) $(OBJS_UTILS)
			@printf "$(ERASE)$(RED)-> All files .o cleaned$(END)\n"
			@printf "$(ERASE)$(RED)-> All files *.gch cleaned$(END)\n"
			@printf "$(ERASE)$(RED)-> libmlx.dylib cleaned$(END)\n"
			@printf "$(ERASE)$(RED)-> All minilibx files cleaned$(END)\n"

re:			fclean all

.PHONY: 	all fclean clean re
