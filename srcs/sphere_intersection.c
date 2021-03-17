/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 17:17:05 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* return 1 if there is an intersection between a ray and an object, otherwise return 0 */
int	sphere_intersection(t_ray *ray, t_scene *rt, t_vectors *P, t_vectors *N)
{
	t_resolve	*res;

	res = initialize_resolve();
	res->sub = vec_minus(ray->origin, rt->element->orig);
	res->a = dot(ray->norm_dir, ray->norm_dir);
	res->b = 2 * dot(ray->norm_dir, res->sub);
	res->c = dot(res->sub, res->sub) - (rt->element->ray * rt->element->ray);
	res->delta = res->b * res->b - (4 * (res->a * res->c));
	if (res->delta < 0)
		return (0); /* if delta is less than 0 -> no intersection return 0 */
	res->t1 = (-res->b - sqrt(res->delta)) / (2 * res->a);
	res->t2 = (-res->b + sqrt(res->delta)) / (2 * res->a);
	if (res->t2 <= 0)
		return (0);
	if (res->t1 >= 0)
		rt->t = res->t1;
	else
		rt->t = res->t2;
	P->x = vec_plus(ray->origin, vec_x(rt->t, ray->norm_dir))->x;
	P->y = -vec_plus(ray->origin, vec_x(rt->t, ray->norm_dir))->y;
	P->z = vec_plus(ray->origin, vec_x(rt->t, ray->norm_dir))->z;
	N->x = unit_vector((vec_minus(P, rt->element->orig)))->x;
	N->y = unit_vector((vec_minus(P, rt->element->orig)))->y;
	N->z = unit_vector((vec_minus(P, rt->element->orig)))->z;
	return (1);
}

void	put_sphere(t_scene *rt, t_ray *ray, int index)
{
	if (sphere_intersection(ray, rt, rt->light->P, rt->light->N))
	{
		t_vectors	*pxl_intensity;

		pxl_intensity = initialize_vector();
		pxl_intensity->x = rt->element->color->b * 100000 * dot(unit_vector(vec_minus(rt->light->orig, rt->light->P)), rt->light->N) / get_norme2(vec_minus(rt->light->orig, rt->light->P));
		pxl_intensity->y = rt->element->color->g * 100000 * dot(unit_vector(vec_minus(rt->light->orig, rt->light->P)), rt->light->N) / get_norme2(vec_minus(rt->light->orig, rt->light->P));
		pxl_intensity->z = rt->element->color->r * 100000 * dot(unit_vector(vec_minus(rt->light->orig, rt->light->P)), rt->light->N) / get_norme2(vec_minus(rt->light->orig, rt->light->P));
		pxl_intensity = check_intensity(pxl_intensity);
		rt->img->data[index - 2] = (unsigned char)pxl_intensity->x * rt->light->ratio;
		rt->img->data[index - 1] = (unsigned char)pxl_intensity->y * rt->light->ratio;
		rt->img->data[index] = (unsigned char)pxl_intensity->z * rt->light->ratio;
	}
}
