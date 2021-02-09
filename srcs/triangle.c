/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:07:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_triangle	*initialize_triangle(void)
{
	t_triangle	*new_triangle;

	if (!(new_triangle = ft_calloc(sizeof(t_triangle), 1)))
		return (NULL);
	new_triangle->first_coord = initialize_vector();
	new_triangle->sec_coord = initialize_vector();
	new_triangle->third_coord = initialize_vector();
	new_triangle->color = initialize_colors();
	return (new_triangle);
}

int	check_triangle_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (check_coordinates(data[3]))
			if (count_comma_format(data[4]) == 2
				&& count_nb_format(data[4]) <= 9)
				return (1);
	error_code(3, type);
	return (0);
}

int	parse_triangle_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**first_coord;
	char	**sec_coord;
	char	**third_coord;
	char	**color;

	first_coord = ft_split(data[1], ",");
	sec_coord = ft_split(data[2], ",");
	third_coord = ft_split(data[3], ",");
	color = ft_split(data[4], ",");
	if (check_triangle_format(str, type, data) == 1)
	{
		mini_rt->tr->first_coord->x = ft_atof(first_coord[0]);
		mini_rt->tr->first_coord->y = ft_atof(first_coord[1]);
		mini_rt->tr->first_coord->z = ft_atof(first_coord[2]);
		mini_rt->tr->sec_coord->x = ft_atof(sec_coord[0]);
		mini_rt->tr->sec_coord->y = ft_atof(sec_coord[1]);
		mini_rt->tr->sec_coord->z = ft_atof(sec_coord[2]);
		mini_rt->tr->third_coord->x = ft_atof(third_coord[0]);
		mini_rt->tr->third_coord->y = ft_atof(third_coord[1]);
		mini_rt->tr->third_coord->z = ft_atof(third_coord[2]);
		mini_rt->tr->color->r = ft_atof(color[0]);
		mini_rt->tr->color->g = ft_atof(color[1]);
		mini_rt->tr->color->b = ft_atof(color[2]);
		return (1);
	}
	return (0);
}
