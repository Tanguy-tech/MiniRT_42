/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:59:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 11:23:15 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_sphere_format(char **data)
{
	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		free(data);
		return (handle_error(SPHERE_FORMAT, 0));
	}
	if (check_coordinates(data[1]) && count_double(data[2]) == 1)
		if (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9)
			if (check_range_color(data[3]))
				return (1);
	return (handle_error(SPHERE_FORMAT, 0));
}

int	parse_sphere_data(t_scene *mini_rt, char **data)
{
	char		**coord;
	char		**color;
	t_element	*sphere;

	coord = ft_split(data[1], ",");
	color = ft_split(data[3], ",");
	sphere = initialize_element();
	if (check_sphere_format(data) == 1)
	{
		sphere->orig.x = ft_atof(coord[0]);
		sphere->orig.y = -ft_atof(coord[1]);
		sphere->orig.z = ft_atof(coord[2]);
		sphere->diam = ft_atof(data[2]);
		sphere->ray = sphere->diam / 2;
		sphere->color.r = ft_atof(color[0]);
		sphere->color.g = ft_atof(color[1]);
		sphere->color.b = ft_atof(color[2]);
		sphere->id = 1;
		return (ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(sphere)));
	}
	return (0);
}
