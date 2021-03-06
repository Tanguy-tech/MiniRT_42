/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:21:54 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/06 10:22:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	check_intensity(double pxl_intensity)
{
	if (pxl_intensity < 0.0)
		pxl_intensity = 0.0;
	if (pxl_intensity > 255.0)
		pxl_intensity = 255.0;
	return (pxl_intensity);
}