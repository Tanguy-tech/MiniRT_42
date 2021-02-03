/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:21 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 09:30:20 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
#define VECTORS_H

#include <math.h>

/* This file contains the vector structure and all the functions relative to it's consctuction */

typedef struct vectors
{
	double	x;			/* Vector cordinate on x axis */
	double	y;			/* Vector cordinate on y axis */
	double	z;			/* Vector cordinate on z axis */
	double	sqrt_norme;	/* Vector squared norme */
	double	norme;		/* Vector norme (total lengh) */
}				s_vectors;

double		get_sqrt_norme(double coord_x, double coord_y, double coord_z);
s_vectors	*initialize_vector(void);

#endif