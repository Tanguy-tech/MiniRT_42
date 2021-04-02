/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:09:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 11:26:35 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_cylinder_format(char **data)
{
	float	height;
	float	diam;

	diam = ft_atof(data[3]);
	height = ft_atof(data[4]);
	if (count_array(data) != 6
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3])
		|| !valid_format(data[4])
		|| !valid_format(data[5]))
	{
		free(data);
		return (handle_error(CYL_FORMAT, 0));
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (diam > 0.0 && height > 0.0)
			if (count_comma_format(data[5]) == 2)
				if (count_nb_format(data[5]) <= 9)
					if (check_range_vector(data[2])
						&& check_range_color(data[5]))
						return (1);
	return (handle_error(CYL_FORMAT, 0));
}

int	parse_cylinder_data(t_scene *mini_rt, char **data)
{
	char		**coord;
	char		**direction;
	char		**color;
	t_element	*cylinder;

	coord = ft_split(data[1], ",");
	direction = ft_split(data[2], ",");
	color = ft_split(data[5], ",");
	cylinder = initialize_element();
	if (check_cylinder_format(data) == 1)
	{
		cylinder->orig = (t_vectors){ft_atof(coord[0]), ft_atof(coord[1]),
			ft_atof(coord[2])};
		cylinder->dir = (t_vectors){ft_atof(direction[0]),
			ft_atof(direction[1]), ft_atof(direction[2])};
		cylinder->diam = ft_atof(data[3]);
		cylinder->height = ft_atof(data[4]);
		cylinder->color = (t_colors){ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2])};
		cylinder->id = 4;
		return (ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(cylinder)));
	}
	return (0);
}
