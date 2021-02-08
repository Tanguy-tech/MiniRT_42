/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:38:08 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 11:46:27 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* Check sphere format */
int	check_sphere_format(char *str, char *type)
{
	if (check_coordinates(catch_coordinates(str)) && count_double(str + ft_strlen(catch_coordinates(str))) == 1 && (count_comma_format(get_rgb_code(str)) == 2 && count_nb_format(get_rgb_code(str)) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE SPHERE INFORMATIONS */
int	parse_sphere_data(char *str, char *type, t_scene *mini_rt)
{
	char	*coord_str;
	char	*diam_str;
	char	*colors_str;
	int		i;

	coord_str = catch_coordinates(str);
	colors_str = get_rgb_code(str);
	i = ft_strlen(coord_str) + 2;
	diam_str = get_double(str, i);
	if (check_sphere_format(str, type) == 1)
	{
		mini_rt->sp->origin_coord->x = ft_atof(trunc_code(coord_str, 0));
		mini_rt->sp->origin_coord->y = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1));
		mini_rt->sp->origin_coord->z = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1 + find_next_code(coord_str) + 1));
		mini_rt->sp->diam = ft_atof(diam_str);
		mini_rt->sp->color->r = ft_atof(trunc_code(colors_str, 0));
		mini_rt->sp->color->g = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1));
		mini_rt->sp->color->b = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1 + find_next_code(colors_str))); 
		ft_putstr("SPHERE DONE\n");
		return (1);
	}
	return (0);
}