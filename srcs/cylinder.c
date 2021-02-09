/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:09:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 09:43:20 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_cylinder	*initialize_cylinder(void)
{
	t_cylinder	*new_cylinder;

	if (!(new_cylinder = ft_calloc(sizeof(t_cylinder), 1)))
		return (NULL);
	new_cylinder->origin_coord = initialize_vector();
	new_cylinder->orientation = initialize_vector();
	new_cylinder->diam = 0.0;
	new_cylinder->height = 0.0;
	new_cylinder->color = initialize_colors();
	return (new_cylinder);
}

int	check_cylinder_format(char *str, char *type, char **data)
{
	float	height;
	float	diam;

	diam = ft_atof(data[2]);
	height = ft_atof(data[3]);
	if (check_coordinates(data[0]) && check_coordinates(data[1]))
		if (diam > 0.0 && height > 0.0)
			if (count_comma_format(data[4]) == 2)
				if (count_nb_format(data[4]) <= 9)
					return (1);
	error_code(3, type);
	return (0);
}

int	parse_cylinder_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;
	char	**coord;
	char	**orientation;
	char	**color;

	data = ft_split(str, " \t");
	coord = ft_split(data[0], ",");
	orientation = ft_split(data[1], ",");
	color = ft_split(data[4], ",");
	if (check_cylinder_format(str, type, data) == 1)
	{
		mini_rt->cy->origin_coord->x = ft_atof(coord[0]);
		mini_rt->cy->origin_coord->y = ft_atof(coord[1]);
		mini_rt->cy->origin_coord->z = ft_atof(coord[2]);
		mini_rt->cy->orientation->x = ft_atof(orientation[0]);
		mini_rt->cy->orientation->y = ft_atof(orientation[1]);
		mini_rt->cy->orientation->z = ft_atof(orientation[2]);
		mini_rt->cy->diam = ft_atof(data[2]);
		mini_rt->cy->height = ft_atof(data[3]);
		mini_rt->cy->color->r = ft_atof(color[0]);
		mini_rt->cy->color->g = ft_atof(color[1]);
		mini_rt->cy->color->b = ft_atof(color[2]);
		return (1);
	}
	return (0);
}
