/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/06 11:07:13 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"
#include "../includes/minirt.h"

t_ray	*initialize_ray(void)
{
	t_ray	*new_ray;

	if (!(new_ray = ft_calloc(sizeof(t_ray), 1)))
		return (NULL);
	new_ray->origin = initialize_vector();
	new_ray->direction = initialize_vector();
	return (new_ray);
}

t_ray	*generate_new_ray(t_scene	*mini_rt)
{
	t_ray	*new_ray;

	new_ray = initialize_ray();
	new_ray->origin->x = mini_rt->cam->coord->x;
	new_ray->origin->y = mini_rt->cam->coord->y;
	new_ray->origin->z = mini_rt->cam->coord->z;
	return (new_ray);
}

void	update_ray(t_ray	*ray, t_scene *mini_rt, double index_hor, double index_ver)
{
	double ratio;
	
	ratio = (1.0 * mini_rt->window->res_y) / (1.0 * mini_rt->window->res_x);
	ray->direction->x = -0.5 + index_hor;
	ray->direction->y = -ratio/2 + index_ver;
	ray->direction->z = mini_rt->window->res_y / tan((mini_rt->cam->fov * 3.14/180));
}