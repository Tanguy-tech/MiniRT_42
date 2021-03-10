/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:05:36 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/10 10:34:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"
#include "../includes/minirt.h"

double	get_norme2(t_vectors *vec)
{
	double	norme2;

	norme2 = (vec->x * vec->x)
		+ (vec->y * vec->y)
		+ (vec->z * vec->z);
	return (norme2);
}

t_vectors	*unit_vector(t_vectors *vector)
{
	t_vectors	*unit_vector;
	double	norm;
	
	if (!(unit_vector = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	norm = sqrt(get_norme2(vector));
	unit_vector->x = vector->x / norm;
	unit_vector->y = vector->y / norm;
	unit_vector->z = vector->z / norm;
	return (unit_vector);
}

t_vectors	*initialize_vector(void)
{
	t_vectors	*new_vector;

	if (!(new_vector = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	new_vector->x = 0.0;
	new_vector->y = 0.0;
	new_vector->z = 0.0;
	return (new_vector);
}

t_vectors	*reinitialize_vector(t_vectors *vector)
{
	vector->x = 0.0;
	vector->y = 0.0;
	vector->z = 0.0;
	return (vector);
}
