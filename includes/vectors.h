/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:21 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 16:16:09 by tbillon          ###   ########lyon.fr   */
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
}				t_vectors;

double		get_sqrt_norme(double coord_x, double coord_y, double coord_z);
t_vectors	*initialize_vector(void);
t_vectors	operator_x(double a, t_vectors b);
t_vectors	operator_plus(t_vectors a, t_vectors b);
t_vectors	operator_minus(t_vectors a, t_vectors b);
t_vectors	operator_div(t_vectors a, double b);
double		dot(t_vectors a, t_vectors b);

#endif