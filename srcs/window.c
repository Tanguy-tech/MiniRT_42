/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/24 08:09:25 by tbillon          ###   ########lyon.fr   */
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
	int i;
	int j;
	t_ray	*ray;
	ray = initialize_ray();
	i = 0;
	j = 0;
	ray->origin->x = mini_rt->cam->coord->x;
	ray->origin->y = mini_rt->cam->coord->y;
	ray->origin->z = mini_rt->cam->coord->z;
	ray->direction->z = mini_rt->window->res_y / (2 * tan((mini_rt->cam->fov * 3.14/180) / 2));
	while (i < mini_rt->window->res_y)
	{
		while (j < mini_rt->window->res_x)
		{
			ray->direction->x = j - mini_rt->window->res_x / 2;
			ray->direction->y = i - mini_rt->window->res_y / 2;
			ray->direction->norme2 = get_norme2(ray->direction->x, ray->direction->y, ray->direction->z);
			normalize(ray->direction);
			dprintf(1, "ray->origin->x= %f\nray->origin->y= %f\nray->origin->z= %f\nN ray->direction->x= %f\nN ray->direction->y= %f\nN ray->direction->z= %f\n", ray->origin->x, ray->origin->y, ray->origin->z, ray->direction->x, ray->direction->y, ray->direction->z);
			if (intersection(ray, mini_rt->sp))
			{
				dprintf(1, "COUCOU");
				mini_rt->window->data[i] = (unsigned char)255;
				//mlx_pixel_put(mini_rt->mlx_ptr, mini_rt->window->win_ptr, i, j, 0x00FFFFFF);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}
