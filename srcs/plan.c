/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/10 13:21:28 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

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
	char	**direction;
	char	**color;
	t_element	*plan;

	coord = ft_split(data[1], ",");
	direction = ft_split(data[2], ",");
	color = ft_split(data[3], ",");
	plan = initialize_element();
	mini_rt->count_elem += 1;
	if (check_plan_format(str, type, data) == 1)
	{
		plan->orig->x = ft_atof(coord[0]);
		plan->orig->y = ft_atof(coord[1]);
		plan->orig->z = ft_atof(coord[2]);
		plan->dir->x = ft_atof(direction[0]);
		plan->dir->y = ft_atof(direction[1]);
		plan->dir->z = ft_atof(direction[2]);
		plan->color->r = ft_atof(color[0]);
		plan->color->g = ft_atof(color[1]);
		plan->color->b = ft_atof(color[2]);
		plan->id = 2;
		ft_lstadd_front(&mini_rt->elem_list, ft_lstnew(plan)); /* add front to write the plan pixel first */
		return (1);
	}
	return (0);
}
