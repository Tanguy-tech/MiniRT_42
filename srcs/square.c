/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 15:51:10 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/shapes.h"
#include "../includes/utils.h"

t_square	*initialize_square(void)
{
	t_square	*new_square;

	if (!(new_square = ft_calloc(sizeof(t_square), 1)))
		return (NULL);
	new_square->coord = initialize_vector();
	new_square->orientation = initialize_vector();
	new_square->height = 0.0;
	new_square->color = initialize_colors();
	return (new_square);
}

/* Check square format */
int	check_square_format(char *str, char *type)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_coordinates(data[0]) && check_coordinates(data[1]) && (ft_atof(data[2]) > 0.0) && (count_comma_format(data[3]) == 2 && count_nb_format(data[3]) <= 9))
		return (1);
	error_code(3, type);
	return (0);
}

/* PARSE SQUARE INFORMATIONS */
int	parse_square_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_square_format(str, type) == 1)
	{
		mini_rt->sq->coord->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->sq->coord->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->sq->coord->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->sq->orientation->x = ft_atof(trunc_code(data[1], 0));
		mini_rt->sq->orientation->y = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->sq->orientation->z = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		mini_rt->sq->height = ft_atof(data[2]);
		mini_rt->sq->color->r = ft_atof(trunc_code(data[3], 0));
		mini_rt->sq->color->g = ft_atof(trunc_code(data[3], find_next_code(data[3]) + 1));
		mini_rt->sq->color->b = ft_atof(trunc_code(data[3], (ft_strlen(trunc_code(data[3], 0)) + ft_strlen(trunc_code(data[3], find_next_code(data[3]) + 1)) + 2)));
		ft_putstr("SQUARE DONE\n");
		return (1);
	}
	return (0);
}