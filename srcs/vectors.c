/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:05:36 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 10:41:23 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	get_sqrt_norme(double coord_x, double coord_y, double coord_z)
{
	double	sqrt_norme;

	sqrt_norme = (coord_x * coord_x) + (coord_y * coord_y) + (coord_z * coord_z);
	return (sqrt_norme);
}

s_vectors	*initialize_vector(void)
{
	s_vectors	*new_vector;

	if (!(new_vector = ft_calloc(sizeof(s_vectors), 1)))
		return (NULL);
	new_vector->x = 0;
	new_vector->y = 0;
	new_vector->z = 0;
	new_vector->sqrt_norme = 0;
	new_vector->norme = 0;
	return (new_vector);
}
