/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:56:02 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_triangle_format(char **data)
{
	if (count_array(data) != 5
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3])
		|| !valid_format(data[4]))
	{
		free(data);
		return (handle_error(TRI_FORMAT, 0));
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (check_coordinates(data[3]))
			if (count_comma_format(data[4]) == 2
				&& count_nb_format(data[4]) <= 9)
				if (check_range_color(data[4]))
					return (1);
	return (handle_error(TRI_FORMAT, 0));
}

int	parse_triangle_data(t_scene *mini_rt, char **data)
{
	char		**first_coord;
	char		**sec_coord;
	char		**third_coord;
	char		**color;
	t_element	*triangle;

	first_coord = ft_split(data[1], ",");
	sec_coord = ft_split(data[2], ",");
	third_coord = ft_split(data[3], ",");
	color = ft_split(data[4], ",");
	triangle = initialize_element();
	mini_rt->count_elem += 1;
	if (check_triangle_format(data) == 1)
	{
		triangle->first_coord.x = ft_atof(first_coord[0]);
		triangle->first_coord.y = ft_atof(first_coord[1]);
		triangle->first_coord.z = ft_atof(first_coord[2]);
		triangle->sec_coord.x = ft_atof(sec_coord[0]);
		triangle->sec_coord.y = ft_atof(sec_coord[1]);
		triangle->sec_coord.z = ft_atof(sec_coord[2]);
		triangle->third_coord.x = -ft_atof(third_coord[0]);
		triangle->third_coord.y = ft_atof(third_coord[1]);
		triangle->third_coord.z = ft_atof(third_coord[2]);
		triangle->color.r = ft_atof(color[0]);
		triangle->color.g = ft_atof(color[1]);
		triangle->color.b = ft_atof(color[2]);
		triangle->id = 5;
		ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(triangle));
		return (1);
	}
	return (0);
}
