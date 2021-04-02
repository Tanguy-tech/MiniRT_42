/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:54:25 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	sphere_intersection(t_thread *th)
{
	t_resolve	res;

	res.sub = vec_minus(th->ray.orig, th->rt.element.orig);
	res.a = dot(th->ray.norm, th->ray.norm);
	res.b = 2 * dot(res.sub, th->ray.norm);
	res.c = dot(res.sub, res.sub) - (th->rt.element.ray * th->rt.element.ray);
	res.delta = res.b * res.b - (4 * (res.a * res.c));
	if (res.delta < 0)
		return (0);
	res.t1 = (-res.b - sqrt(res.delta)) / (2 * res.a);
	res.t2 = (-res.b + sqrt(res.delta)) / (2 * res.a);
	if (res.t2 < 0)
		return (0);
	if (res.t1 > 0)
		res.t_res = res.t1;
	else
		res.t_res = res.t2;
	th->rt.t = res.t_res;
	th->P.x = vec_plus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).x;
	th->P.y = -vec_plus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).y;
	th->P.z = vec_plus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).z;
	th->N.x = unit_vec(vec_minus(th->P, th->rt.element.orig)).x;
	th->N.y = unit_vec(vec_minus(th->P, th->rt.element.orig)).y;
	th->N.z = unit_vec(vec_minus(th->P, th->rt.element.orig)).z;
	return (1);
}

void	put_sphere(t_thread *th, int index)
{
	t_vectors	pxl;

	if (sphere_intersection(th))
	{
		pxl.x = ((th->rt.element.color.b + th->rt.light.color.b) / 2)
			* 100000 * dot(unit_vec(vec_minus(th->rt.light.orig, th->P)), th->N)
			/ get_norme2(vec_minus(th->rt.light.orig, th->P));
		pxl.y = ((th->rt.element.color.g + th->rt.light.color.g) / 2)
			* 100000 * dot(unit_vec(vec_minus(th->rt.light.orig, th->P)), th->N)
			/ get_norme2(vec_minus(th->rt.light.orig, th->P));
		pxl.z = ((th->rt.element.color.r + th->rt.light.color.r) / 2)
			* 100000 * dot(unit_vec(vec_minus(th->rt.light.orig, th->P)), th->N)
			/ get_norme2(vec_minus(th->rt.light.orig, th->P));
		pxl = check_intensity(pxl);
		th->rt.img->data[index - 2] = (unsigned char)pxl.x * th->rt.light.ratio;
		th->rt.img->data[index - 1] = (unsigned char)pxl.y * th->rt.light.ratio;
		th->rt.img->data[index] = (unsigned char)pxl.z * th->rt.light.ratio;
	}
}
