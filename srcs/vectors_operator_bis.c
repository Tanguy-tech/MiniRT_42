/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operator_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:03:03 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:07:16 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/vectors.h"
#include "../includes/minirt.h"

t_vectors	*vec_x(double a, t_vectors *b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a * b->x;
	res->y = a * b->y;
	res->z = a * b->z;
	return (res);
}

t_vectors	*vec_inv_x(t_vectors *a, double b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a->x * b;
	res->y = a->y * b;
	res->z = a->z * b;
	return (res);
}


t_vectors	*vec_div(t_vectors *a, double b)
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = a->x / b;
	res->y = a->y / b;
	res->z = a->z / b;
	return (res);
}

t_vectors	*vec_cross_prod(t_vectors *a, t_vectors *b) /* Produit vectoriel - Cross produ */
{
	t_vectors	*res;

	if (!(res = ft_calloc(sizeof(t_vectors), 1)))
		return (NULL);
	res->x = (a->y * b->z) - (a->z * b->y);
	res->y = (-a->x * b->z) - (a->z * b->x);
	res->z = (a->x * b->y) - (a->y * b->x);
	return (res);
}