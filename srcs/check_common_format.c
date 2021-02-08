/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 11:47:21 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* Check format for R type */
int	check_R_format(char *str, char *type)
{
	int count;
	int i;
	
	count = 0;
	i = 0;
	while (ft_isdigit(str[i]) || ft_iswhitespace(str[i]))
	{
		if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	error_code(3, type);
	return (0);
}

/* Check format for A type */
int	check_A_format(char *str, char *type)
{
	if (count_double(str) == 1 && count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9)
		return (1);
	error_code(3, type);
	return (0);
}

/* Check format for c type */
int	check_c_format(char *str, char *type)
{
	if ((check_coordinates(catch_coordinates(str)) && check_coordinates(str + ft_strlen(catch_coordinates(str)) + 1)) && (get_angle(str) >= 0 && get_angle(str) <= 180))
		return (1);
	error_code(3, type);
	return (0);
}

/* Check format for l type */
int	check_l_format(char *str, char *type)
{
	if (check_coordinates(catch_coordinates(str)) && count_double(str + ft_strlen(catch_coordinates(str))) == 1 && (count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}
