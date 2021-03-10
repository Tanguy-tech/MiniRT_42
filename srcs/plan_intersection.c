/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:21:13 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/10 13:31:37 by tbillon          ###   ########lyon.fr   */
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
	if (res->t1 < 0 || rt->t < res->t1)
		return (0);
	rt->t = res->t1;
	return (1);
}

void put_plan(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	if (plan_intersection(mini_rt, mini_rt->element, mini_rt->light->orig, mini_rt->light->P))
	{
		mini_rt->img->data[index - 2] = (unsigned char)mini_rt->element->color->b * mini_rt->light->ratio;
		mini_rt->img->data[index - 1] = (unsigned char)mini_rt->element->color->g * mini_rt->light->ratio;
		mini_rt->img->data[index] = (unsigned char)mini_rt->element->color->r * mini_rt->light->ratio;
	}
}