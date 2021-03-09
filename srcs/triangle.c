/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 13:15:11 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_triangle_format(char *str, char *type, char **data)
{
	if (count_array(data) != 5
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3])
		|| !valid_format(data[4]))
	{
		error_code(3, type);
		free(data);
		exit(0);
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if (check_coordinates(data[3]))
			if (count_comma_format(data[4]) == 2
				&& count_nb_format(data[4]) <= 9)
				if (check_range_colors(data[4]))
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
	t_element	*triangle;

	first_coord = ft_split(data[1], ",");
	sec_coord = ft_split(data[2], ",");
	third_coord = ft_split(data[3], ",");
	color = ft_split(data[4], ",");
	triangle = initialize_element();
	mini_rt->count_elem += 1;
	if (check_triangle_format(str, type, data) == 1)
	{
		mini_rt->element->first_coord->x = ft_atof(first_coord[0]);
		mini_rt->element->first_coord->y = ft_atof(first_coord[1]);
		mini_rt->element->first_coord->z = ft_atof(first_coord[2]);
		mini_rt->element->sec_coord->x = ft_atof(sec_coord[0]);
		mini_rt->element->sec_coord->y = ft_atof(sec_coord[1]);
		mini_rt->element->sec_coord->z = ft_atof(sec_coord[2]);
		mini_rt->element->third_coord->x = ft_atof(third_coord[0]);
		mini_rt->element->third_coord->y = ft_atof(third_coord[1]);
		mini_rt->element->third_coord->z = ft_atof(third_coord[2]);
		mini_rt->element->color->r = ft_atof(color[0]);
		mini_rt->element->color->g = ft_atof(color[1]);
		mini_rt->element->color->b = ft_atof(color[2]);
		triangle->id = 5;
		ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(mini_rt->element));
		return (1);
	}
	return (0);
}
