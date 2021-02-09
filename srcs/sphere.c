/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:59:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:09:43 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_sphere	*initialize_sphere(void)
{
	t_sphere	*new_sphere;

	if (!(new_sphere = ft_calloc(sizeof(t_sphere), 1)))
		return (NULL);
	new_sphere->color = initialize_colors();
	new_sphere->diam = 0.0;
	new_sphere->origin_coord = initialize_vector();
	return (new_sphere);
}

int	check_sphere_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[1]) && count_double(data[2]) == 1)
		if (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9)
			return (1);
	error_code(3, type);
	return (0);
}

int	parse_sphere_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**color;

	coord = ft_split(data[1], ",");
	color = ft_split(data[3], ",");
	if (check_sphere_format(str, type, data) == 1)
	{
		mini_rt->sp->origin_coord->x = ft_atof(coord[0]);
		mini_rt->sp->origin_coord->y = ft_atof(coord[1]);
		mini_rt->sp->origin_coord->z = ft_atof(coord[2]);
		mini_rt->sp->diam = ft_atof(data[2]);
		mini_rt->sp->color->r = ft_atof(color[0]);
		mini_rt->sp->color->g = ft_atof(color[1]);
		mini_rt->sp->color->b = ft_atof(color[2]);
		ft_putstr("SPHERE DONE\n");
		return (1);
	}
	return (0);
}
