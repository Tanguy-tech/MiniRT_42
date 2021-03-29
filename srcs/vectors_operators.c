/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:58:04 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 13:21:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"
#include "../includes/minirt.h"

t_vectors	vec_plus(t_vectors a, t_vectors b)
{
	t_vectors	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vectors	vec_minus(t_vectors a, t_vectors b)
{
	t_vectors	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vectors	vec_xvec(t_vectors a, t_vectors b)
{
	t_vectors	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vectors	vec_divvec(t_vectors a, t_vectors b)
{
	t_vectors	res;

	res.x = a.x / b.x;
	res.y = a.y / b.y;
	res.z = a.z / b.z;
	return (res);
}

double	dot(t_vectors a, t_vectors b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
