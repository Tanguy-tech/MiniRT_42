/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/08 10:22:24 by tbillon          ###   ########lyon.fr   */
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
	new_window->pxl_intensity = initialize_vector();
	return (new_window);
}

void	display_elements(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	t_list	*tmp;

	tmp = mini_rt->elem_list;
	while(tmp)
	{
		mini_rt->element = tmp->content;
		if (mini_rt->element->id == 1)
			put_sphere(mini_rt, ray, index);
		// if (mini_rt->element->id == 2)
		// 	put_plan(mini_rt, ray, index, j);
		// if (mini_rt->element->id == 3)
			
		// if (mini_rt->element->id == 4)

		// if (mini_rt->element->id == 5)

		tmp = tmp->next;
	}
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
	t_ray	*ray;
	
	ray = generate_new_ray(mini_rt);
	j = 0;
	k = 2;
	while (j < mini_rt->window->res_y)
	{
		i = 0;
		while (i < mini_rt->window->res_x)
		{
			update_ray(ray, mini_rt, i / mini_rt->window->res_x, j / mini_rt->window->res_x);
			/* normalized vector ! */
			ray->direction = unit_vector(ray->direction);
			reinitialize_vector(mini_rt->window->pxl_intensity);
			display_elements(mini_rt, ray, k, j);
			i++;
			k+= 4;
		}
		j++;
	}
	return (0);
}
