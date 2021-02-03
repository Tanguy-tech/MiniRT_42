/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:24:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 09:35:25 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include "vectors.h"

typedef	struct ray
{
	s_vectors	origin;		/* Origin point of the ray (vector point) */
	s_vectors	direction;	/* Direction of the ray (vector) */
}				s_ray;


#endif