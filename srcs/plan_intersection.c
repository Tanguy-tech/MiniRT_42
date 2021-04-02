/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:21:13 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:53:21 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	plan_intersection(t_thread *th)
{
	t_resolve	res;

	res.deamon = dot(th->rt.element.dir, th->ray.dir);
	if (res.deamon > 1e-6)
	{
		res.sub = vec_minus(th->rt.element.orig, th->ray.orig);
		res.t_res = dot(res.sub, th->rt.element.dir) / res.deamon;
		th->rt.t = res.t_res;
		th->P.x = vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).x;
		th->P.y = -vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).y;
		th->P.z = vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).z;
		th->N.x = unit_vec(vec_minus(th->P, th->rt.element.orig)).x;
		th->N.y = unit_vec(vec_minus(th->P, th->rt.element.orig)).y;
		th->N.z = unit_vec(vec_minus(th->P, th->rt.element.orig)).z;
		return (res.t_res >= 0);
	}
	return (0);
}

void	put_plan(t_thread *th, int index)
{
	t_vectors	pxl;

	if (plan_intersection(th))
	{
		pxl.x = ((th->rt.element.color.b + th->rt.light.color.b) / 2)
			* (1 - dot(unit_vec(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl.y = ((th->rt.element.color.g + th->rt.light.color.g) / 2)
			* (1 - dot(unit_vec(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl.z = ((th->rt.element.color.r + th->rt.light.color.r) / 2)
			* (1 - dot(unit_vec(vec_plus(th->rt.light.orig, th->P)), th->N));
		pxl = check_intensity(pxl);
		th->rt.img->data[index - 2] = (unsigned char)pxl.x * th->rt.light.ratio;
		th->rt.img->data[index - 1] = (unsigned char)pxl.y * th->rt.light.ratio;
		th->rt.img->data[index] = (unsigned char)pxl.z * th->rt.light.ratio;
	}
}
