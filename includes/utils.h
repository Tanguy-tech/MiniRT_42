/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 10:40:40 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* This file contains all functions and tools to help the general program works (libft like) */
int		error(int error_code);
int		errors_check(int ac, char **av);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_strlen(char *str);
void	*ft_calloc(int count, int size);
char	*str_add_char(char *str, char c);
char	*ft_substr(char *str, int begin, int len_max);
int		to_find(char *str, char c);
int		get_next_line(int fd, char **line);

#endif