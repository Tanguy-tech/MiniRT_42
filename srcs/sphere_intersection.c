/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/05 14:25:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* return 1 if there is an intersection between a ray and an object, otherwise return 0 */
int	sphere_intersection(t_ray *ray, t_sphere *sphere, t_vectors *P, t_vectors *N)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	res1;
	double	res2;
	double	t;
	t_vectors	*oc;

	if (!(oc = ft_calloc(sizeof(t_vectors), 1)))
		return (-1);
	oc = operator_minus(ray->origin, sphere->origin_coord);
	a = dot(ray->direction, ray->direction);
	b = 2 * dot(oc, ray->direction);
	c = dot(oc, oc) - (sphere->ray * sphere->ray);
	delta = b * b - (4 * (a * c));
	if (delta < 0)
		return (0); /* if delta is less than 0 -> no intersection return 0 */
	res1 = (-b - sqrt(delta)) / (2 * a);
	res2 = (-b + sqrt(delta)) / (2 * a);
	if (res2 < 0)
		return (0);
	if (res1 > 0)
		t = res1;
	else
		t = res2;
	P->x = operator_plus(ray->origin, operator_x(t, ray->direction))->x;
	P->y = -operator_plus(ray->origin, operator_x(t, ray->direction))->y;
	P->z = operator_plus(ray->origin, operator_x(t, ray->direction))->z;
	N->x = unit_vector((operator_minus(P, sphere->origin_coord)))->x;
	N->y = unit_vector((operator_minus(P, sphere->origin_coord)))->y;
	N->z = unit_vector((operator_minus(P, sphere->origin_coord)))->z;
	sphere->t = t;
	return (1);
}

void	put_sphere(t_scene *mini_rt, t_ray *ray, int index)
{
	if (sphere_intersection(ray, mini_rt->sp, mini_rt->light->P, mini_rt->light->N))
	{
		// t_ray	*ray_light;
		// t_vectors	*P_light;
		// t_vectors	*N_light;
		// double		t_light;
		// double		d_light2;

		// ray_light = initialize_ray();
		// P_light = initialize_vector();
		// N_light	= initialize_vector();
		// ray_light->origin->x = mini_rt->light->P->x +0.01 * mini_rt->light->N->x;
		// ray_light->origin->y = mini_rt->light->P->y +0.01 * mini_rt->light->N->y;
		// ray_light->origin->z = mini_rt->light->P->z +0.01 * mini_rt->light->N->z;
		// ray_light->direction = unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P));
		// d_light2 = get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);
		// t_light = mini_rt->sp->t;
		// if (sphere_intersection(ray_light, mini_rt->sp, P_light, N_light))
		// {
		// 	if (t_light*t_light < d_light2)
		// 	{
		// 		mini_rt->window->pxl_intensity->x = 255.0;
		// 		mini_rt->window->pxl_intensity->y = 255.0;
		// 		mini_rt->window->pxl_intensity->z = 255.0;
		// 	}
		// }
		// else
		// {
			mini_rt->window->pxl_intensity->x = mini_rt->sp->color->b * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->y = mini_rt->sp->color->g * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->z = mini_rt->sp->color->r * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->x = check_intensity(mini_rt->window->pxl_intensity->x);
			mini_rt->window->pxl_intensity->y = check_intensity(mini_rt->window->pxl_intensity->y);
			mini_rt->window->pxl_intensity->z = check_intensity(mini_rt->window->pxl_intensity->z);
		//}
		mini_rt->window->data[index - 2] = (unsigned char)mini_rt->window->pxl_intensity->x * mini_rt->light->light_ratio;
		mini_rt->window->data[index - 1] = (unsigned char)mini_rt->window->pxl_intensity->y * mini_rt->light->light_ratio;
		mini_rt->window->data[index] = (unsigned char)mini_rt->window->pxl_intensity->z * mini_rt->light->light_ratio;
	}
}
