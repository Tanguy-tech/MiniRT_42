/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:40:31 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/05 16:12:10 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		plan_intersection(t_ray *ray, t_plan *plan, t_vectors *P, t_vectors *N)
{
	t_ray		*gen_plan;
	double		t;
	t_vectors	*diff;
	double		d;
	double		e;

	diff = initialize_vector();
	gen_plan = initialize_ray();
	gen_plan->origin->x = ray->direction->x;
	gen_plan->origin->y = plan->coord->y;
	gen_plan->origin->z = plan->coord->z;
	gen_plan->direction->x = plan->orientation->x;
	gen_plan->direction->y = plan->orientation->y;
	gen_plan->direction->z = plan->orientation->z;
	t = dot(gen_plan->direction, ray->direction);
	if (t > 0)
	{
		P->x = operator_plus(ray->origin, operator_x(t*10, ray->direction))->x;
		P->y = operator_plus(ray->origin, operator_x(t*10, ray->direction))->y;
		P->z = operator_plus(ray->origin, operator_x(t*10, ray->direction))->z;
		N->x = unit_vector((operator_minus(P, gen_plan->origin)))->x;
		N->y = unit_vector((operator_minus(P, gen_plan->origin)))->y;
		N->z = unit_vector((operator_minus(P, gen_plan->origin)))->z;
		plan->t = t;
		return (1);
	}
	return (0);
}

void	put_plan(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	if (plan_intersection(ray, mini_rt->pl, mini_rt->light->P, mini_rt->light->N))
	{
		// t_ray	*ray_light;
		// double	d_light2;
		// double	t_light;

		// ray_light = initialize_ray();
		// ray_light->origin->x = mini_rt->sp->P->x +0.01 * mini_rt->sp->N->x;
		// ray_light->origin->y = mini_rt->sp->P->y +0.01 * mini_rt->sp->N->y;
		// ray_light->origin->z = mini_rt->sp->P->z +0.01 * mini_rt->sp->N->z;
		// ray_light->direction = unit_vector(operator_minus(mini_rt->sp->origin_coord, mini_rt->sp->P));
		// d_light2 = get_norme2(operator_minus(mini_rt->sp->origin_coord, mini_rt->sp->P)->x, operator_minus(mini_rt->sp->origin_coord, mini_rt->sp->P)->y, operator_minus(mini_rt->sp->origin_coord, mini_rt->sp->P)->z);
		// t_light = mini_rt->pl->t;
		// if (plan_intersection(ray_light, mini_rt->pl, mini_rt->sp->P, mini_rt->sp->N) && (t_light*t_light < d_light2))
		// {
		// 	mini_rt->window->pxl_intensity->x = 0.0;
		// 	mini_rt->window->pxl_intensity->y = 0.0;
		// 	mini_rt->window->pxl_intensity->z = 0.0;
		// }
		// else
		// {
			mini_rt->window->pxl_intensity->x = mini_rt->pl->color->b * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->y = mini_rt->pl->color->g * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->z = mini_rt->pl->color->r * 100000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);// / d_light2;
			mini_rt->window->pxl_intensity->x = check_intensity(mini_rt->window->pxl_intensity->x);
			mini_rt->window->pxl_intensity->y = check_intensity(mini_rt->window->pxl_intensity->y);
			mini_rt->window->pxl_intensity->z = check_intensity(mini_rt->window->pxl_intensity->z);
		// }
		mini_rt->window->data[index - 2] = (unsigned char)mini_rt->window->pxl_intensity->x * ((j * 1.0)/ mini_rt->window->res_y);
		mini_rt->window->data[index - 1] = (unsigned char)mini_rt->window->pxl_intensity->y * ((j * 1.0)/ mini_rt->window->res_y);
		mini_rt->window->data[index] = (unsigned char)mini_rt->window->pxl_intensity->z * ((j * 1.0)/ mini_rt->window->res_y);
	}
}
