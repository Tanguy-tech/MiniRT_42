/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:21 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 15:08:35 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
#define VECTORS_H

#include <math.h>

/* This file contains the vector structure and all the functions relative to it's consctuction */

typedef struct vectors
{
	double	x;	/* Vector cordinate on x axis */
	double	y;	/* Vector cordinate on y axis */
	double	z;	/* Vector cordinate on z axis */
}				s_vectors;

#endif