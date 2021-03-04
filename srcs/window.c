/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/04 13:02:57 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/vectors.h"

t_window	*initialize_window(void)
{
	t_window	*new_window;

	if (!(new_window = ft_calloc(sizeof(t_window), 1)))
		return (NULL);
	new_window->res_x = 0;
	new_window->res_y = 0;
	new_window->title = "\0";
	return (new_window);
}

double	check_intensity(double pxl_intensity)
{
	if (pxl_intensity < 0.0)
		pxl_intensity = 0.0;
	if (pxl_intensity > 255.0)
		pxl_intensity = 255.0;
	return (pxl_intensity);
}

int	set_img(t_scene	*mini_rt)
{
	mini_rt->window->img_ptr = mlx_new_image(mini_rt->mlx_ptr, mini_rt->window->res_x, mini_rt->window->res_y);
	if (!(mini_rt->window->img_ptr = mlx_new_image(mini_rt->mlx_ptr,
				mini_rt->window->res_x,
				mini_rt->window->res_y)))
		return (error_code(4, NULL));
	if (!(mini_rt->window->data = mlx_get_data_addr(mini_rt->window->img_ptr,
				&mini_rt->window->bit_per_pixel,
				&mini_rt->window->size_line,
				&mini_rt->window->endian)))
		return (error_code(4, NULL));
	double i;
	double j;
	int k;
	double ratio;
	double index_hor;
	double index_ver;
	t_ray	*ray;
	t_vectors *pxl_intensity;
	
	ray = initialize_ray();
	pxl_intensity = initialize_vector();
	j = 0;
	k = 2;
	ray->origin->x = mini_rt->cam->coord->x;
	ray->origin->y = mini_rt->cam->coord->y;
	ray->origin->z = mini_rt->cam->coord->z;
	ratio = (1.0 * mini_rt->window->res_y) / (1.0 * mini_rt->window->res_x);
	while (j < mini_rt->window->res_y)
	{
		i = 0;
		while (i < mini_rt->window->res_x)
		{
			index_hor = i / mini_rt->window->res_x;
			index_ver = j / mini_rt->window->res_x;
			ray->direction->x = -0.5 + index_hor;
			ray->direction->y = -ratio/2 + index_ver;
			ray->direction->z = mini_rt->window->res_y / tan((mini_rt->cam->fov * 3.14/180));
			/* normalized vector ! */
			ray->direction = unit_vector(ray->direction);
			reinitialize_vector(pxl_intensity);
			if (mini_rt->sp->count > 0)
				put_sphere(mini_rt, pxl_intensity, ray, k);
			i++;
			k+= 4;
		}
		j++;
	}
	return (0);
}
