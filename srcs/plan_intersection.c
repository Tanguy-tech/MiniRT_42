/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:40:31 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:07:37 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		plan_intersection(t_ray *ray, t_element *plan, t_vectors *P, t_vectors *N)
{
	t_ray		*gen_plan;
	double		t;
	double		d;
	double		e;

	gen_plan = initialize_ray();
	gen_plan->origin->x = ray->direction->x;
	gen_plan->origin->y = plan->orig->y;
	gen_plan->origin->z = plan->orig->z;
	gen_plan->direction->x = plan->dir->x;
	gen_plan->direction->y = plan->dir->y;
	gen_plan->direction->z = plan->dir->z;
	t = dot(gen_plan->direction, ray->direction);
	if (t > 0)
	{
		P->x = vec_plus(ray->origin, vec_x(t, ray->direction))->x;
		P->y = vec_plus(ray->origin, vec_x(t, ray->direction))->y;
		P->z = vec_plus(ray->origin, vec_x(t, ray->direction))->z;
		N->x = unit_vector((vec_minus(P, gen_plan->origin)))->x;
		N->y = unit_vector((vec_minus(P, gen_plan->origin)))->y;
		N->z = unit_vector((vec_minus(P, gen_plan->origin)))->z;
		return (1);
	}
	return (0);
}

void	put_plan(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	if (plan_intersection(ray, mini_rt->element, mini_rt->light->P, mini_rt->light->N))
	{
		mini_rt->img->data[index - 2] = (unsigned char)mini_rt->element->color->r * ((j * 1.0)/ mini_rt->res->y);
		mini_rt->img->data[index - 1] = (unsigned char)mini_rt->element->color->g * ((j * 1.0)/ mini_rt->res->y);
		mini_rt->img->data[index] = (unsigned char)mini_rt->element->color->b * ((j * 1.0)/ mini_rt->res->y);
	}
}
