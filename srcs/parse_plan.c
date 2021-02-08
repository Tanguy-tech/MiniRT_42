/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:40:10 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 11:44:47 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* Check plan format */
int		check_plan_format(char *str, char *type)
{
	char	*coord_str;
	char	*or_str;

	coord_str = catch_coordinates(str);
	or_str = catch_coordinates(str + ft_strlen(coord_str) + 1);
	if (check_coordinates(coord_str) && check_coordinates(or_str) && (count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE PLAN INFORMATIONS */
int	parse_plan_data(char *str, char *type, t_scene *mini_rt)
{
	char	*coord_str;
	char	*or_str;
	char	*colors_str;

	coord_str = catch_coordinates(str);
	or_str = catch_coordinates(str + ft_strlen(coord_str) + 1);
	colors_str = get_rgb_code(str);
	if (check_plan_format(str, type) == 1)
	{
		mini_rt->pl->coord->x = ft_atof(trunc_code(coord_str, 0));
		mini_rt->pl->coord->y = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1));
		mini_rt->pl->coord->z = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1 + find_next_code(coord_str) + 1));
		mini_rt->pl->orientation->x = ft_atof(trunc_code(or_str, 0));
		mini_rt->pl->orientation->y = ft_atof(trunc_code(or_str, find_next_code(or_str) + 1));
		mini_rt->pl->orientation->z = ft_atof(trunc_code(get_rgb_code(or_str), find_next_code(get_rgb_code(or_str)) + 1 + find_next_code(get_rgb_code(or_str)) + 1));
		mini_rt->pl->color->r = ft_atof(trunc_code(colors_str, 0));
		mini_rt->pl->color->g = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1));
		mini_rt->pl->color->b = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1 + find_next_code(colors_str) + 1));
		ft_putstr("PLAN DONE\n");
		return (1);
	}
	return (0);
}
