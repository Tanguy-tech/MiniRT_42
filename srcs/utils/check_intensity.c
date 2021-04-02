/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:21:54 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:01:30 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vectors	check_intensity(t_vectors pxl_intensity)
{
	if (pxl_intensity.x < 0.0)
		pxl_intensity.x = 0.0;
	if (pxl_intensity.y < 0.0)
		pxl_intensity.y = 0.0;
	if (pxl_intensity.z < 0.0)
		pxl_intensity.z = 0.0;
	if (pxl_intensity.x > 255.0)
		pxl_intensity.x = 255.0;
	if (pxl_intensity.y > 255.0)
		pxl_intensity.y = 255.0;
	if (pxl_intensity.z > 255.0)
		pxl_intensity.z = 255.0;
	return (pxl_intensity);
}
