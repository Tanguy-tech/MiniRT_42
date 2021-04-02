/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:38:00 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_res_format(char *str, char **data)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (count_array(data) != 3
		|| !valid_format(data[1])
		|| !valid_format(data[2]))
	{
		free(data);
		return (handle_error(RES_FORMAT, 0));
	}
	while (ft_isdigit(str[i]) || ft_iswhitespace(str[i]))
	{
		if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (handle_error(RES_FORMAT, 0));
}

int	check_amb_format(char **data)
{
	double	ratio;

	if (count_array(data) != 3
		|| !valid_format(data[1])
		|| !valid_format(data[2]))
	{
		free(data);
		return (handle_error(AMB_FORMAT, 0));
	}
	ratio = atof(data[1]);
	if (count_double(data[1]) == 1 && (ratio >= 0.0 && ratio <= 1.0))
		if (count_comma_format(data[2]) == 2 && count_nb_format(data[2]) <= 9)
			if (check_range_color(data[2]))
				return (1);
	return (handle_error(AMB_FORMAT, 0));
}

int	check_c_format(char **data)
{
	double	angle;

	angle = ft_atof(data[3]);
	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		free(data);
		return (handle_error(CAM_FORMAT, 0));
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (check_range_vector(data[2]))
			if (angle >= 0 && angle <= 180)
				return (1);
	return (handle_error(CAM_FORMAT, 0));
}

int	check_l_format(char **data)
{
	double	ratio;

	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		free(data);
		return (handle_error(LIGHT_FORMAT, 0));
	}
	ratio = atof(data[2]);
	if (check_coordinates(data[1]) && count_double(data[2]) == 1
		&& (ratio >= 0.0 && ratio <= 1.0))
		if (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9)
			if (check_range_color(data[3]))
				return (1);
	return (handle_error(LIGHT_FORMAT, 0));
}
