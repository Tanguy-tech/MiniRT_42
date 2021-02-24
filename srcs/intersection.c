/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/23 14:48:16 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	test_sign(double delta, double a, double b)
{
	double	res1;
	double	res2;

	res1 = (-b - sqrt(delta)) / (2 * a);
	res2 = (-b + sqrt(delta)) / (2 * a);
	if (res2 > 0) /* if res2 > 0 there is intersection */
		return (1);
	return (0);
}

/* return 1 if there is an intersection between a ray and an object, otherwise return 0 */
int	intersection(t_ray *ray, t_sphere *sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	t_vectors	*minus_res;
	double	norme2;

	if (!(minus_res = ft_calloc(sizeof(t_vectors), 1)))
		return (-1);
	minus_res = operator_minus(ray->origin, sphere->origin_coord);
	norme2 = get_norme2(minus_res->x, minus_res->y, minus_res->z);
	a = 1;
	b = 2 * dot(ray->direction, minus_res);
	c = norme2 - sphere->ray * sphere->ray;	
	delta = b * b - (4 * (a * c));
	dprintf(1, "a= %f\nb= %f\nc= %f\n", a, b, c);
	dprintf(1, "delta= %f\n\n", delta);
	if (delta < 0)
		return (0); /* if delta is less than 0 -> no intersection return 0 */
	if (test_sign(delta, a, b))
		return (1);
	return (0);
}
