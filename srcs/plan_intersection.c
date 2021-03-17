/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:21:13 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 13:44:04 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	plan_intersection(t_scene *rt, t_element *plan, t_vectors *ori, t_vectors *dir)
{
	t_resolve	*res;

	res = initialize_resolve();
	res->a = dot(vec_minus(ori, plan->orig), plan->dir);
	res->b = dot(dir, plan->dir);
	if (res->b == 0 || (res->a < 0 && res->b < 0) || (res->a > 0 && res->b > 0))
		return (0);
	res->t1 = -res->a / res->b;
	if (res->t1 < 0)
		return (0);
	rt->t = res->t1;
	plan->P->x = vec_plus(rt->ray->origin, vec_x(rt->t, rt->ray->norm_dir))->x;
	plan->P->y = -vec_plus(rt->ray->origin, vec_x(rt->t, rt->ray->norm_dir))->y;
	plan->P->z = vec_plus(rt->ray->origin, vec_x(rt->t, rt->ray->norm_dir))->z;
	return (1);
}

void put_plan(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	if (plan_intersection(mini_rt, mini_rt->element, mini_rt->light->orig, mini_rt->light->P))
	{
		t_vectors	*pxl_intensity;

		pxl_intensity = initialize_vector();
		pxl_intensity = vec_xcol(dot(mini_rt->light->orig, mini_rt->element->P), mini_rt->element->color);
		check_intensity(pxl_intensity);
		mini_rt->img->data[index - 2] = (unsigned char)pxl_intensity->x * mini_rt->light->ratio;
		mini_rt->img->data[index - 1] = (unsigned char)pxl_intensity->y * mini_rt->light->ratio;
		mini_rt->img->data[index] = (unsigned char)pxl_intensity->z * mini_rt->light->ratio;
	}
}