/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 12:42:44 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_square_format(char *type, char **data)
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
		if ((ft_atof(data[3]) > 0.0) && (count_comma_format(data[4]) == 2))
			if (count_nb_format(data[4]) <= 9)
				if (check_range_vector(data[2]) && check_range_colors(data[4]))
					return (1);
	error_code(3, type);
	return (0);
}

int	parse_square_data(char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**direction;
	char	**color;
	t_element	*square;

	coord = ft_split(data[1], ",");
	direction = ft_split(data[2], ",");
	color = ft_split(data[4], ",");
	square = initialize_element();
	mini_rt->count_elem += 1;
	if (check_square_format(type, data) == 1)
	{
		square->orig.x = ft_atof(coord[0]);
		square->orig.y = ft_atof(coord[1]);
		square->orig.z = ft_atof(coord[2]);
		square->dir.x = ft_atof(direction[0]);
		square->dir.y = ft_atof(direction[1]);
		square->dir.z = ft_atof(direction[2]);
		square->height = ft_atof(data[3]);
		square->color.r = ft_atof(color[0]);
		square->color.g = ft_atof(color[1]);
		square->color.b = ft_atof(color[2]);
		square->id = 3;
		ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(square));
		return (1);
	}
	return (0);
}
