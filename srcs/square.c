/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 11:23:33 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/element.h"
#include "../includes/utils.h"

int	check_square_format(char **data)
{
	if (count_array(data) != 5
		|| !valid_format(data[1])
		|| !valid_format(data[2])
		|| !valid_format(data[3])
		|| !valid_format(data[4]))
	{
		free(data);
		return (handle_error(SQUARE_FORMAT, 0));
	}
	if (check_coordinates(data[1]) && check_coordinates(data[2]))
		if ((ft_atof(data[3]) > 0.0) && (count_comma_format(data[4]) == 2))
			if (count_nb_format(data[4]) <= 9)
				if (check_range_vector(data[2]) && check_range_color(data[4]))
					return (1);
	return (handle_error(SQUARE_FORMAT, 0));
}

int	parse_square_data(t_scene *mini_rt, char **data)
{
	char		**coord;
	char		**direction;
	char		**color;
	t_element	*square;

	coord = ft_split(data[1], ",");
	direction = ft_split(data[2], ",");
	color = ft_split(data[4], ",");
	square = initialize_element();
	if (check_square_format(data) == 1)
	{
		square->orig = (t_vectors){ft_atof(coord[0]), -ft_atof(coord[1]),
			ft_atof(coord[2])};
		square->dir = (t_vectors){ft_atof(direction[0]), ft_atof(direction[1]),
			ft_atof(direction[2])};
		square->height = ft_atof(data[3]);
		square->color = (t_colors){ft_atof(color[0]), ft_atof(color[1]),
			ft_atof(color[2])};
		square->id = 3;
		return (ft_lstadd_back(&mini_rt->elem_list, ft_lstnew(square)));
	}
	return (0);
}
