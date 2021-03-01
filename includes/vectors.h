/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:21 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/25 09:36:13 by tbillon          ###   ########lyon.fr   */
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
}				t_vectors;

double		get_norme2(double coord_x, double coord_y, double coord_z);
t_vectors	*initialize_vector(void);
t_vectors	*operator_x(double a, t_vectors *b);
t_vectors	*operator_plus(t_vectors *a, t_vectors *b);
t_vectors	*operator_minus(t_vectors *a, t_vectors *b);
t_vectors	*operator_div(t_vectors *a, double b);
t_vectors	*operator_xvec(t_vectors *a, t_vectors *b);
t_vectors	*operator_divvec(t_vectors *a, t_vectors *b);
t_vectors	*operator_cross_prod(t_vectors *a, t_vectors *b);
double		dot(t_vectors *a, t_vectors *b);
t_vectors	*unit_vector(t_vectors *vector);

#endif