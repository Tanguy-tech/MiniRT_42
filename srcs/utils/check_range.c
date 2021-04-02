/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:15:10 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:02:14 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_range_color(char *code)
{
	char	**rgb_code;
	float	r;
	float	g;
	float	b;

	rgb_code = ft_split(code, ",");
	r = atof(rgb_code[0]);
	g = atof(rgb_code[1]);
	b = atof(rgb_code[2]);
	if ((r < 0.0 || r > 255.0) || (g < 0.0 || g > 255.0)
		|| (b < 0.0 || b > 255.0))
		return (0);
	return (1);
}

int	check_range_vector(char *code)
{
	char	**dir_code;
	float	x;
	float	y;
	float	z;

	dir_code = ft_split(code, ",");
	x = atof(dir_code[0]);
	y = atof(dir_code[1]);
	z = atof(dir_code[2]);
	if ((x < -1.0 || x > 1.0) || (y < -1.0 || y > 1.0)
		|| (z < -1.0 || z > 1.0))
		return (0);
	return (1);
}
