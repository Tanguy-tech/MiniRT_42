/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:21 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/16 13:16:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
#define VECTORS_H

#include <math.h>
#include "colors.h"

/* This file contains the vector structure and all the functions relative to it's consctuction */

typedef struct vectors
{
	double	x;			/* Vector cordinate on x axis */
	double	y;			/* Vector cordinate on y axis */
	double	z;			/* Vector cordinate on z axis */
}				t_vectors;

double		get_norme2(t_vectors *vec);
t_vectors	*initialize_vector(void);
t_vectors	*reinitialize_vector(t_vectors *vector);
t_vectors	*vec_x(double a, t_vectors *b);
t_vectors	*vec_inv_x(t_vectors *a, double b);
t_vectors	*vec_plus(t_vectors *a, t_vectors *b);
t_vectors	*vec_minus(t_vectors *a, t_vectors *b);
t_vectors	*vec_div(t_vectors *a, double b);
t_vectors	*vec_xvec(t_vectors *a, t_vectors *b);
t_vectors	*vec_divvec(t_vectors *a, t_vectors *b);
t_vectors	*vec_cross_prod(t_vectors *a, t_vectors *b);
double		dot(t_vectors *a, t_vectors *b);
t_vectors	*unit_vector(t_vectors *vector);
t_vectors	*vec_xcol(double a, t_colors *b);

#endif