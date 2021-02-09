/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 08:39:42 by tbillon          ###   ########lyon.fr   */
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

/* Check plan format */
int		check_plan_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[0]) && check_coordinates(data[1]) && (count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE PLAN INFORMATIONS */
int	parse_plan_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_plan_format(str, type, data) == 1)
	{
		mini_rt->pl->coord->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->pl->coord->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->pl->coord->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->pl->orientation->x = ft_atof(trunc_code(data[1], 0));
		mini_rt->pl->orientation->y = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->pl->orientation->z = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		mini_rt->pl->color->r = ft_atof(trunc_code(data[2], 0));
		mini_rt->pl->color->g = ft_atof(trunc_code(data[2], find_next_code(data[2]) + 1));
		mini_rt->pl->color->b = ft_atof(trunc_code(data[2], (ft_strlen(trunc_code(data[2], 0)) + ft_strlen(trunc_code(data[2], find_next_code(data[2]) + 1)) + 2)));
		ft_putstr("PLAN DONE\n");
		return (1);
	}
	return (0);
}
