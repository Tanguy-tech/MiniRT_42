/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 15:57:31 by tbillon          ###   ########lyon.fr   */
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
	char	**data;

	data = ft_split(str, " \t");
	if (count_double(data[0]) == 1 && count_comma_format(data[1]) == 2 && count_nb_format(data[1]) <= 9)
		return (1);
	error_code(3, type);
	return (0);
}

/* Check format for c type */
int	check_c_format(char *str, char *type)
{
	char	**data;
	double	angle;

	data = ft_split(str, " \t");
	angle = ft_atof(data[2]);
	if ((check_coordinates(data[0]) && check_coordinates(data[1]) && (angle >= 0 && angle <= 180)))
		return (1);
	error_code(3, type);
	return (0);
}

/* Check format for l type */
int	check_l_format(char *str, char *type)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_coordinates(data[0]) && count_double(data[1]) == 1 && (count_comma_format(data[2]) == 2 && count_nb_format(data[2]) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}
