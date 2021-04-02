/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 11:22:04 by tbillon          ###   ########lyon.fr   */
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
	if (check_triangle_format(data) == 1)
	{
		triangle->first_coord = (t_vectors){ft_atof(first_coord[0]),
			ft_atof(first_coord[1]), ft_atof(first_coord[2])};
		triangle->sec_coord = (t_vectors){ft_atof(sec_coord[0]),
			ft_atof(sec_coord[1]), ft_atof(sec_coord[2])};
		triangle->third_coord = (t_vectors){-ft_atof(third_coord[0]),
			ft_atof(third_coord[1]), ft_atof(third_coord[2])};
		triangle->color = (t_colors){ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2])};
		triangle->id = 5;
		return (ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(triangle)));
	}
	return (0);
}
