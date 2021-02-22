/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:05:36 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/22 15:06:46 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"
#include "../includes/minirt.h"

double	get_norme2(double coord_x, double coord_y, double coord_z)
{
	double	sqrt_norme;

	sqrt_norme = (coord_x * coord_x)
		+ (coord_y * coord_y)
		+ (coord_z * coord_z);
	return (sqrt_norme);
}

void	normalize(t_vectors *vector)
{
	double	norm;
	
	norm = sqrt(vector->sqrt_norme);
	vector->x /= norm;
	vector->y /= norm;
	vector->z /= norm;
}

t_vectors	*initialize_vector(void)
{
	t_vectors	*new_vector;

	if (!(new_vector = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	new_vector->x = 0.0;
	new_vector->y = 0.0;
	new_vector->z = 0.0;
	new_vector->sqrt_norme = get_norme2(new_vector->x,
			new_vector->y,
			new_vector->z);
	new_vector->norme = 0.0;
	return (new_vector);
}
