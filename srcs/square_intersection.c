/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:36:30 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:53:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	square_intersection(t_thread *th)
{
	t_resolve	res;

	res.a = dot(vec_minus(th->ray.orig, th->rt.element.orig),
			th->rt.element.dir);
	res.b = dot(th->ray.dir, th->rt.element.dir);
	if (res.b == 0 || (res.a < 0 && res.b < 0) || (res.a > 0 && res.b > 0))
		return (0);
	res.t_res = -res.a / res.b;
	res.sub = vec_minus(vec_plus(vec_inv_x(th->ray.dir, res.t_res),
				th->ray.orig), th->rt.element.orig);
	res.t2 = th->rt.element.height / 2;
	if (ft_abs(res.sub.x) > res.t2 || ft_abs(res.sub.y) > res.t2
		|| ft_abs(res.sub.z) > res.t2)
		return (0);
	if (res.t_res > 0)
		th->rt.t = res.t_res;
	th->P.x = vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).x;
	th->P.y = -vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).y;
	th->P.z = vec_minus(th->ray.orig, vec_x(res.t_res, th->ray.norm)).z;
	th->N.x = unit_vec(vec_minus(th->P, th->rt.element.orig)).x;
	th->N.y = unit_vec(vec_minus(th->P, th->rt.element.orig)).y;
	th->N.z = unit_vec(vec_minus(th->P, th->rt.element.orig)).z;
	return (1);
}

void	put_square(t_thread *th, int index)
{
	t_vectors	pxl;

	if (square_intersection(th))
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
