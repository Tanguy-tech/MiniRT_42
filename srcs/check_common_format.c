/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 11:18:23 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* Check format for R type */
int	check_R_format(char *str)
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
	error_code(3);
	return (0);
}

/* Check format for A type */
int	check_A_format(char *str)
{
	if (count_double(str) == 1 && count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9)
		return (1);
	error_code(3);
	return (0);
}

/* Check format for c type */
int	check_c_format(char *str)
{
	if ((check_coordinates(catch_coordinates(str)) && check_coordinates(str + ft_strlen(catch_coordinates(str)) + 1)) && (get_angle(str) >= 0 && get_angle(str) <= 180))
		return (1);
	error_code(3);
	return (0);
}

/* Check format for l type */



int		check_format(char *str, char *type)
{
	/* Check the str format for the parsing process */
	if (ft_strncmp(type, "R", ft_strlen(type)) == 0)
		return (check_R_format(str));
	if (ft_strncmp(type, "A", ft_strlen(type)) == 0)
		return (check_A_format(str));
	if (ft_strncmp(type, "c", ft_strlen(type)) == 0)
		return (check_c_format(str));
	return (0);
}
