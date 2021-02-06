/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:59:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:02:45 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/utils.h"

t_sphere	*initialize_sphere(void)
{
	t_sphere	*new_sphere;

	if (!(new_sphere = ft_calloc(sizeof(t_sphere), 1)))
		return (NULL);
	new_sphere->color = initialize_colors();
	new_sphere->diam = 0.0;
	new_sphere->origin_coord = initialize_vector();
	return (new_sphere);
}