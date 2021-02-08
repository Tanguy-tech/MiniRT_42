/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:09:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 15:50:38 by tbillon          ###   ########lyon.fr   */
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

/* Check cylinder format */
int	check_cylinder_format(char *str, char *type)
{
	char	**data;
	float	height;
	float	diam;

	data = ft_split(str, " \t");
	diam = ft_atof(data[2]);
	height = ft_atof(data[3]);
	if (check_coordinates(data[0]) && check_coordinates(data[1]) && (diam > 0.0 && height > 0.0) && (count_comma_format(data[4]) == 2 && count_nb_format(data[4]) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}


/* PARSE CYLINDER INFORMATIONS */
int	parse_cylinder_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_cylinder_format(str, type) == 1)
	{
		mini_rt->cy->origin_coord->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->cy->origin_coord->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->cy->origin_coord->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->cy->orientation->x = ft_atof(trunc_code(data[1], 0));
		mini_rt->cy->orientation->y = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->cy->orientation->z = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		mini_rt->cy->diam = ft_atof(data[2]);
		mini_rt->cy->height = ft_atof(data[3]);
		mini_rt->cy->color->r = ft_atof(trunc_code(data[4], 0));
		mini_rt->cy->color->g = ft_atof(trunc_code(data[4], find_next_code(data[4]) + 1));
		mini_rt->cy->color->b = ft_atof(trunc_code(data[4], (ft_strlen(trunc_code(data[4], 0)) + ft_strlen(trunc_code(data[4], find_next_code(data[4]) + 1)) + 2)));
		ft_putstr("CYLINDER DONE\n");
		return (1);
	}
	return (0);
}