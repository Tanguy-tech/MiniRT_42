/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:58:04 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/22 11:19:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vectors.h"
#include "../includes/minirt.h"

t_vectors	*operator_plus(t_vectors *a, t_vectors *b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}

t_vectors	*operator_minus(t_vectors *a, t_vectors *b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
	return (res);
}

t_vectors	*operator_x(double a, t_vectors *b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a * b->x;
	res->y = a * b->y;
	res->z = a * b->z;
	return (res);
}

t_vectors	*operator_div(t_vectors *a, double b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a->x / b;
	res->y = a->y / b;
	res->z = a->z / b;
	return (res);
}

double	dot(t_vectors *a, t_vectors *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}
