/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:09:15 by tbillon          ###   ########lyon.fr   */
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
	return (new_plan);
}

int	check_plan_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (count_comma_format(get_rgb_code(str)) == 2)
			if (count_nb_format(get_rgb_code(str)) <= 9)
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
		ft_putstr("PLAN DONE\n");
		return (1);
	}
	return (0);
}
