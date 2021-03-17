/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 17:17:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	*initialize_ray(void)
{
	t_ray	*new_ray;

	if (!(new_ray = ft_calloc(sizeof(t_ray), 1)))
		return (NULL);
	new_ray->origin = initialize_vector();
	new_ray->direction = initialize_vector();
	new_ray->norm_dir = initialize_vector();
	return (new_ray);
}

t_ray	*gen_ray(t_scene *rt, double index_hor, double index_ver)
{
	t_ray	*ray;
	
	ray = initialize_ray();
	rt->cam = rt->cam_list->content;
	ray->origin->x = rt->cam->orig->x;
	ray->origin->y = rt->cam->orig->y;
	ray->origin->z = rt->cam->orig->z;
	ray->direction->x = -0.5 + index_hor;
	ray->direction->y = -rt->res->ratio / 2 + index_ver;
	ray->direction->z = rt->res->y / (2 * tan((rt->cam->fov * 3.14/180)) / 2);
	ray->norm_dir = unit_vector(ray->direction);
	return (ray);
}

void	update_ray(t_ray *ray, t_scene *rt, double index_hor, double index_ver)
{
	ray->direction->x = -0.5 + index_hor;
	ray->direction->y = -rt->res->ratio / 2 + index_ver;
	ray->norm_dir = unit_vector(ray->direction);
}
