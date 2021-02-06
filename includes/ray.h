/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:24:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:54:13 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vectors.h"

typedef	struct ray
{
	t_vectors	origin;		/* Origin point of the ray (vector point) */
	t_vectors	direction;	/* Direction of the ray (vector) */
}				t_ray;


#endif