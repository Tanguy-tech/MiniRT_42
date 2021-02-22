/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/22 15:17:05 by tbillon          ###   ########lyon.fr   */
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

	minus_res = operator_minus(ray->origin, sphere->origin_coord); /* don't forget to normalize the vector ray before */
	a = 1;
	b = 2 * dot(ray->direction, minus_res);
	c = get_norme2(minus_res->x, minus_res->y, minus_res->z) - sphere->ray * sphere->ray;
	delta = b * b - (4 * (a * c));
	//dprintf(1, "%f\n%f\n%f\n\n", minus_res->x, minus_res->y, minus_res->z);
	dprintf(1, "a= %f\nb= %f\nc= %f\nray->orientation->x= %f\nray->orientation->y= %f\nray->orientation->z= %f\ndelta= %f\n", a, b, c, ray->direction->x, ray->direction->y, ray->direction->z, delta);
	if (delta < 0)
		return (0); /* if delat is less than 0 -> no intersection return 0 */
	if (test_sign(delta, a, b))
		return (1);
	return (0);
}
