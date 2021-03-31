/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:51:44 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/31 16:40:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// int	cylinder_intersection(t_thread *th)
// {

// 	return (1);
// }

// void	put_cylinder(t_thread *th, int index)
// {
// 	if (cylinder_intersection(th))
// 	{
// 		t_vectors	pxl_intensity;
		
// 		pxl_intensity.x = ((th->rt.element.color.b + th->rt.light.color.b) / 2) * dot(unit_vector(vec_minus(th->rt.light.orig, th->P)), th->N);
// 		pxl_intensity.y = ((th->rt.element.color.g + th->rt.light.color.g) / 2) * dot(unit_vector(vec_minus(th->rt.light.orig, th->P)), th->N);
// 		pxl_intensity.z = ((th->rt.element.color.r + th->rt.light.color.r) / 2) * dot(unit_vector(vec_minus(th->rt.light.orig, th->P)), th->N);
// 		pxl_intensity = check_intensity(pxl_intensity);
// 		th->rt.img->data[index - 2] = (unsigned char)pxl_intensity.x * th->rt.light.ratio;
// 		th->rt.img->data[index - 1] = (unsigned char)pxl_intensity.y * th->rt.light.ratio;
// 		th->rt.img->data[index] = (unsigned char)pxl_intensity.z * th->rt.light.ratio;
// 	}
// }