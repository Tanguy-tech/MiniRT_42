/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:11:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_res_format(char *str, char *type)
{
	int	count;
	int	i;

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

int	check_amb_format(char *str, char *type, char **data)
{
	if (count_double(data[1]) == 1)
		if (count_comma_format(data[2]) == 2 && count_nb_format(data[2]) <= 9)
			return (1);
	error_code(3, type);
	return (0);
}

int	check_c_format(char *str, char *type, char **data)
{
	double	angle;

	angle = ft_atof(data[3]);
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (angle >= 0 && angle <= 180)
			return (1);
	error_code(3, type);
	return (0);
}

int	check_l_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[1]) && count_double(data[2]) == 1)
		if (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9)
			return (1);
	error_code(3, type);
	return (0);
}
