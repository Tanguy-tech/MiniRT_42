/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 08:39:29 by tbillon          ###   ########lyon.fr   */
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

/* Check triangle format */
int	check_triangle_format(char *str, char *type, char **data)
{
	if (check_coordinates(data[0]) && check_coordinates(data[1]) && check_coordinates(data[2]) && (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE TRIANGLE INFORMATIONS */
int	parse_triangle_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_triangle_format(str, type, data) == 1)
	{
		mini_rt->tr->first_coord->x = ft_atof(trunc_code(data[0], 0)); 
		mini_rt->tr->first_coord->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->tr->first_coord->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->tr->sec_coord->x = ft_atof(trunc_code(data[1], 0));
		mini_rt->tr->sec_coord->y = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->tr->sec_coord->z = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		mini_rt->tr->third_coord->x = ft_atof(trunc_code(data[2], 0));
		mini_rt->tr->third_coord->y = ft_atof(trunc_code(data[2], find_next_code(data[2]) + 1));
		mini_rt->tr->third_coord->z = ft_atof(trunc_code(data[2], (ft_strlen(trunc_code(data[2], 0)) + ft_strlen(trunc_code(data[2], find_next_code(data[2]) + 1)) + 2)));
		mini_rt->tr->color->r = ft_atof(trunc_code(data[3], 0));
		mini_rt->tr->color->g = ft_atof(trunc_code(data[3], find_next_code(data[3]) + 1));
		mini_rt->tr->color->b = ft_atof(trunc_code(data[3], (ft_strlen(trunc_code(data[3], 0)) + ft_strlen(trunc_code(data[3], find_next_code(data[3]) + 1)) + 2)));
		ft_putstr("TRIANGLE DONE\n");
		return (1);
	}
	return (0);
}