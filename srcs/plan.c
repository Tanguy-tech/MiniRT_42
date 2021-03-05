/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/05 15:16:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_plan	*initialize_plan(void)
{
	t_plan	*new_plan;

	if (!(new_plan = ft_calloc(sizeof(t_plan), 1)))
		return (NULL);
	new_plan->coord = initialize_vector();
	new_plan->orientation = initialize_vector();
	new_plan->color = initialize_colors();
	new_plan->count = 0;
	new_plan->t = 0.0;
	return (new_plan);
}

int	check_plan_format(char *str, char *type, char **data)
{
	if (count_array(data) != 4
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (count_comma_format(data[3]) == 2)
			if (count_nb_format(data[3]) <= 9)
				if (check_range_vector(data[2]) && check_range_colors(data[3]))
					return (1);
	error_code(3, type);
	return (0);
}

int	parse_plan_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**orientation;
	char	**color;

	coord = ft_split(data[1], ",");
	orientation = ft_split(data[2], ",");
	color = ft_split(data[3], ",");
	if (check_plan_format(str, type, data) == 1)
	{
		mini_rt->pl->coord->x = ft_atof(coord[0]);
		mini_rt->pl->coord->y = ft_atof(coord[1]);
		mini_rt->pl->coord->z = ft_atof(coord[2]);
		mini_rt->pl->orientation->x = ft_atof(orientation[0]);
		mini_rt->pl->orientation->y = ft_atof(orientation[1]);
		mini_rt->pl->orientation->z = ft_atof(orientation[2]);
		mini_rt->pl->color->r = ft_atof(color[0]);
		mini_rt->pl->color->g = ft_atof(color[1]);
		mini_rt->pl->color->b = ft_atof(color[2]);
		mini_rt->pl->count += 1;
		return (1);
	}
	return (0);
}
