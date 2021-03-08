/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/08 09:03:34 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "scenes.h"

/* This file contains all functions and tools to help the general program works (libft like) */
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_strlen(char *str);
void	*ft_calloc(int count, int size);
char	*str_add_char(char *str, char c);
char	*ft_substr(char *str, int begin, int len_max);
int		to_find(char *str, char c);
int		get_next_line(int fd, char **line);
int		ft_atoi(char *str);
float	ft_atof(char *str);
int		check_fac(int fac, int i);
int		check_neg(int fac, char c);
char	*ft_strrchr(char *s, int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_iswhitespace(char c);
int		count_double(char *str);
int		count_nb_format(char *str);
int		count_comma_format(char *str);
double	ft_strtod(char *str);
int		find_next_code(char *str);
int		get_angle(char *str);
char	*catch_coordinates(char *str);
int		check_coordinates(char *str);
int		size_num(int x);
char	*get_double(char *str, int i);
char	**ft_split(char *s, char *c);
int		count_array(char **array);
int		valid_format(char *str);
int		is_punctuation(char c);
double		ft_abs(double n);

void	ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);

#endif
