/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:09:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/08 10:02:15 by tbillon          ###   ########lyon.fr   */
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
	new_cylinder->count = 0;
	return (new_cylinder);
}

int	check_cylinder_format(char *str, char *type, char **data)
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
		error_code(3, type);
		free(data);
		exit(0);
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (diam > 0.0 && height > 0.0)
			if (count_comma_format(data[5]) == 2)
				if (count_nb_format(data[5]) <= 9)
					if (check_range_vector(data[2]) && check_range_colors(data[5]))
						return (1);
	error_code(3, type);
	return (0);
}

int	parse_cylinder_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**direction;
	char	**color;
	t_element	*cylinder;

	coord = ft_split(data[1], ",");
	direction = ft_split(data[2], ",");
	color = ft_split(data[5], ",");
	cylinder = initialize_element();
	if (check_cylinder_format(str, type, data) == 1)
	{
		cylinder->orig->x = ft_atof(coord[0]);
		cylinder->orig->y = ft_atof(coord[1]);
		cylinder->orig->z = ft_atof(coord[2]);
		cylinder->dir->x = ft_atof(direction[0]);
		cylinder->dir->y = ft_atof(direction[1]);
		cylinder->dir->z = ft_atof(direction[2]);
		cylinder->diam = ft_atof(data[3]);
		cylinder->height = ft_atof(data[4]);
		cylinder->color->r = ft_atof(color[0]);
		cylinder->color->g = ft_atof(color[1]);
		cylinder->color->b = ft_atof(color[2]);
		ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(cylinder));
		return (1);
	}
	return (0);
}
