/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/19 12:50:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_res_format(char *str, char *type, char **data)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (count_array(data) != 3
		|| !valid_format(data[1])
		|| !valid_format(data[2]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
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

int	check_amb_format(char *type, char **data)
{
	if (count_array(data) != 3
		|| !valid_format(data[1])
		|| !valid_format(data[2]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
	double ratio;
	
	ratio = atof(data[1]);
	if (count_double(data[1]) == 1 && (ratio >= 0.0 && ratio <= 1.0))
		if (count_comma_format(data[2]) == 2 && count_nb_format(data[2]) <= 9)
			if (check_range_colors(data[2]))
				return (1);
	error_code(3, type);
	return (0);
}

int	check_c_format(char *type, char **data)
{
	double	angle;

	angle = ft_atof(data[3]);
	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (check_range_vector(data[2]))
			if (angle >= 0 && angle <= 180) /* Check if x coordinate of camera is negative! otherwise it means the cam is too close to the window */
				return (1);
	error_code(3, type);
	return (0);
}

int	check_l_format(char *type, char **data)
{
	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
	double ratio;
	
	ratio = atof(data[2]);
	if (check_coordinates(data[1]) && count_double(data[2]) == 1 && (ratio >= 0.0 && ratio <= 1.0))
		if (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9)
			if (check_range_colors(data[3]))
				return (1);
	error_code(3, type);
	return (0);
}
