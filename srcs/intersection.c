/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 14:33:07 by tbillon          ###   ########lyon.fr   */
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

	/* don't forget to normalize the vector ray before */
	a = 1;
	b = 2 * dot(ray->origin, ray->origin - sphere->origin_coord);
	c = get_sqrt_norme(operator_minus(ray->origin, sphere->origin_coord)->x,
			operator_minus(ray->origin, sphere->origin_coord)->y,
			operator_minus(ray->origin, sphere->origin_coord)->z) - sphere->ray * sphere->ray;
	delta = b * b - (4 * (a * c));
	if (delta < 0)
		return (0); /* if delat is less than 0 -> no intersection return 0 */
	if (test_sign(delta, a, b))
		return (1);
	return (0);
}
