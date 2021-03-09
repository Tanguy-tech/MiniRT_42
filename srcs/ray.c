/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:41:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:08:06 by tbillon          ###   ########lyon.fr   */
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

void	update_ray(t_scene *mini_rt, double index_hor, double index_ver)
{
	double aspect;
	t_vectors	*point;

	aspect = (double)mini_rt->res->x / (double)mini_rt->res->y;
	mini_rt->res->x < mini_rt->res->y ? index_hor *= aspect : 0;
	mini_rt->res->x > mini_rt->res->y ? index_ver /= aspect : 0;
	point = vec_plus(vec_plus(vec_plus(vec_inv_x(mini_rt->cam->right, index_hor), vec_inv_x(mini_rt->cam->up, index_ver)), mini_rt->ray->origin), unit_vector(mini_rt->cam->dir));
	mini_rt->ray->direction = unit_vector(vec_minus(point, mini_rt->ray->origin));
}