/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:31:43 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/01 13:44:13 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	triangle_intersection(t_thread *th)
{
	t_resolve	res;
	t_vectors	v1;
	t_vectors	v2;
	t_vectors	tvec;
	t_vectors	pvec;

	v1 = vec_minus(th->rt.element.sec_coord, th->rt.element.first_coord);
	v2 = vec_minus(th->rt.element.third_coord, th->rt.element.first_coord);
	pvec = vec_cross_prod(th->ray.dir, v2);
	res.delta = dot(v1, pvec);
	if (ft_abs(res.delta) < 0.00001)
		return (0);
	res.deamon = 1 / res.delta;
	tvec = vec_minus(th->ray.orig, th->rt.element.first_coord);
	res.a = dot(tvec, pvec) * res.deamon;
	if (res.a < 0 || res. a > 1)
		return (0);
	tvec = vec_cross_prod(tvec, v1);
	res.b = dot(th->ray.dir, tvec) * res.deamon;
	if (res.b < 0 || res.a + res.b > 1)
		return (0);
	th->rt.t = dot(v2, tvec) * res.deamon;
	return (1);
}

void	put_triangle(t_thread *th, int index)
{
	if (triangle_intersection(th))
	{
		th->rt.img->data[index - 2] = (unsigned char)th->rt.element.color.b * th->rt.light.ratio;
		th->rt.img->data[index - 1] = (unsigned char)th->rt.element.color.g * th->rt.light.ratio;
		th->rt.img->data[index] = (unsigned char)th->rt.element.color.r * th->rt.light.ratio;
	}
}