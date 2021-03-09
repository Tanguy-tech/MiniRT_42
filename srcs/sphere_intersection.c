/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:21:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* return 1 if there is an intersection between a ray and an object, otherwise return 0 */
int	sphere_intersection(t_ray *ray, t_element *sphere, t_vectors *P, t_vectors *N)
{
	t_resolve	*r;
	double		t;

	r = initialize_resolve();
	r->sub = vec_minus(ray->origin, sphere->orig);
	r->a = dot(ray->direction, ray->direction);
	r->b = 2 * dot(ray->direction, r->sub);
	r->c = dot(r->sub, r->sub) - (sphere->ray * sphere->ray);
	r->delta = r->b * r->b - (4 * (r->a * r->c));
	if (r->delta < 0)
		return (0); /* if delta is less than 0 -> no intersection return 0 */
	r->t1 = (-r->b - sqrt(r->delta)) / (2 * r->a);
	r->t2 = (-r->b + sqrt(r->delta)) / (2 * r->a);
	if (r->t2 <= 0)
		return (0);
	if (r->t1 >= 0)
		t = r->t1;
	else
		t = r->t2;
	P->x = vec_plus(ray->origin, vec_x(t, ray->direction))->x;
	P->y = vec_plus(ray->origin, vec_x(t, ray->direction))->y;
	P->z = vec_plus(ray->origin, vec_x(t, ray->direction))->z;
	N->x = unit_vector((vec_minus(P, sphere->orig)))->x;
	N->y = unit_vector((vec_minus(P, sphere->orig)))->y;
	N->z = unit_vector((vec_minus(P, sphere->orig)))->z;
	return (1);
}

void	put_sphere(t_scene *mini_rt, t_ray *ray, int index)
{
	if (sphere_intersection(ray, mini_rt->element, mini_rt->light->P, mini_rt->light->N))
	{
		t_vectors	pxl_intensity;

		pxl_intensity = (t_vectors){0,0,0};
		pxl_intensity.x = mini_rt->element->color->b * 100000 * dot(unit_vector(vec_minus(mini_rt->light->orig, mini_rt->light->P)), mini_rt->light->N) / get_norme2(vec_minus(mini_rt->light->orig, mini_rt->light->P)->x, vec_minus(mini_rt->light->orig, mini_rt->light->P)->y, vec_minus(mini_rt->light->orig, mini_rt->light->P)->z);
		pxl_intensity.y = mini_rt->element->color->g * 100000 * dot(unit_vector(vec_minus(mini_rt->light->orig, mini_rt->light->P)), mini_rt->light->N) / get_norme2(vec_minus(mini_rt->light->orig, mini_rt->light->P)->x, vec_minus(mini_rt->light->orig, mini_rt->light->P)->y, vec_minus(mini_rt->light->orig, mini_rt->light->P)->z);
		pxl_intensity.z = mini_rt->element->color->r * 100000 * dot(unit_vector(vec_minus(mini_rt->light->orig, mini_rt->light->P)), mini_rt->light->N) / get_norme2(vec_minus(mini_rt->light->orig, mini_rt->light->P)->x, vec_minus(mini_rt->light->orig, mini_rt->light->P)->y, vec_minus(mini_rt->light->orig, mini_rt->light->P)->z);
		pxl_intensity.x = check_intensity(pxl_intensity.x);
		pxl_intensity.y = check_intensity(pxl_intensity.y);
		pxl_intensity.z = check_intensity(pxl_intensity.z);
		mini_rt->img->data[index - 2] = (unsigned char)pxl_intensity.x * mini_rt->light->light_ratio;
		mini_rt->img->data[index - 1] = (unsigned char)pxl_intensity.y * mini_rt->light->light_ratio;
		mini_rt->img->data[index] = (unsigned char)pxl_intensity.z * mini_rt->light->light_ratio;
	}
}
