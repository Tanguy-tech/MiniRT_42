/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/03 15:42:33 by tbillon          ###   ########lyon.fr   */
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
	int l;
	double ratio;
	double index_hor;
	double index_ver;
	double pxl_intensity;
	t_ray	*ray;
	
	ray = initialize_ray();
	j = 0;
	k = 2;
	l = 0;
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
			ray->direction->x = -0.5 + index_hor;/* point origine x + index horizontal */
			ray->direction->y = -ratio/2 + index_ver;/* point origine y + index vertical */
			ray->direction->z = mini_rt->window->res_y / tan((mini_rt->cam->fov * 3.14/180));
			/* normaliser vecteur ?? */
			ray->direction = unit_vector(ray->direction);
			pxl_intensity = 0.0;
			if (sphere_intersection(ray, mini_rt->sp, mini_rt->light->P, mini_rt->light->N)) /* if intersection pixel is red */
			{
				pxl_intensity = (1000000 * dot(unit_vector(operator_minus(mini_rt->light->coord, mini_rt->light->P)), mini_rt->light->N)) / get_norme2(operator_minus(mini_rt->light->coord, mini_rt->light->P)->x, operator_minus(mini_rt->light->coord, mini_rt->light->P)->y, operator_minus(mini_rt->light->coord, mini_rt->light->P)->z);
				/* if intersection with light -> ligh a pixel with light color * ratio */
				mini_rt->window->data[k - 2] = (unsigned char)pxl_intensity;
				mini_rt->window->data[k - 1] = (unsigned char)pxl_intensity;
				mini_rt->window->data[k] = (unsigned char)pxl_intensity;
			}
			i++;
			k+= 4;
			l+= 4;
		}
		j++;
	}
	return (0);
}
