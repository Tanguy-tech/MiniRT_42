/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/10 14:38:18 by tbillon          ###   ########lyon.fr   */
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
	return (new_ray);
}

void	gen_ray(t_scene *rt)
{
	rt->ray->origin->x = rt->cam->orig->x;
	rt->ray->origin->y = rt->cam->orig->y;
	rt->ray->origin->z = rt->cam->orig->z;
}

void	update_ray(t_scene *mini_rt, double index_hor, double index_ver)
{
	mini_rt->ray->direction->x = -0.5 + index_hor;
	mini_rt->ray->direction->y = -mini_rt->res->ratio / 2 + index_ver;
	mini_rt->ray->direction->z = mini_rt->res->y / (2 * tan((mini_rt->cam->fov * 3.14/180)) / 2);
	mini_rt->ray->direction = unit_vector(mini_rt->ray->direction);
}