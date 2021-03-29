/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 08:51:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	*initialize_ray(void)
{
	t_ray	*new_ray;

	if (!(new_ray = ft_calloc(sizeof(t_ray), 1)))
		return (NULL);
	new_ray->orig = initialize_vector();
	new_ray->dir = initialize_vector();
	new_ray->norm_dir = initialize_vector();
	return (new_ray);
}

t_ray	*gen_ray(t_scene *rt, double index_hor, double index_ver)
{
	t_ray	*ray;
	
	ray = initialize_ray();
	ray->orig->x = rt->cam.orig.x;
	ray->orig->y = rt->cam.orig.y;
	ray->orig->z = rt->cam.orig.z;
	ray->dir->x = (2 * ((index_hor + 0.5) / rt->res.x) - 1) * tan((rt->cam.fov * M_PI/180) / 2);
	ray->dir->y = (2 * ((index_ver + 0.5) / rt->res.y) - 1) * rt->res.ratio * tan((rt->cam.fov * M_PI/180) / 2);
	ray->dir->z = 1;
	return (ray);
}

void	update_ray(t_thread *th, double index_hor, double index_ver)
{
	th->ray->dir->x = (2 * ((index_hor + 0.5) / th->rt.res.x) - 1) * tan((th->rt.cam.fov * M_PI/180) / 2);
	th->ray->dir->y = (2 * ((index_ver + 0.5) / th->rt.res.y) - 1) * th->rt.res.ratio * tan((th->rt.cam.fov * M_PI/180) / 2);
	th->ray->norm_dir = unit_vector(th->ray->dir);
}
