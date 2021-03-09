/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:09:05 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/vectors.h"

void	display_elements(t_scene *mini_rt, t_ray *ray, int index, int j)
{
	t_list	*tmp;

	tmp = mini_rt->elem_list;
	while(tmp)
	{
		mini_rt->element = tmp->content;
		if (mini_rt->element->id == 1)
			put_sphere(mini_rt, ray, index);
		if (mini_rt->element->id == 2)
			put_plan(mini_rt, ray, index, j);
		// if (mini_rt->element->id == 3)
			
		// if (mini_rt->element->id == 4)

		// if (mini_rt->element->id == 5)

		tmp = tmp->next;
	}
}

int	set_img(t_scene	*mini_rt)
{
	if (!(mini_rt->img->ptr = mlx_new_image(mini_rt->mlx_ptr,
				mini_rt->res->x,
				mini_rt->res->y)))
		return (error_code(4, NULL));
	if (!(mini_rt->img->data = mlx_get_data_addr(mini_rt->img->ptr,
				&mini_rt->img->bpp,
				&mini_rt->img->size_line,
				&mini_rt->img->endian)))
		return (error_code(4, NULL));
	double i;
	double j;
	int k;
	
	mini_rt->ray->origin->x = mini_rt->cam->orig->x;
	mini_rt->ray->origin->y = mini_rt->cam->orig->y;
	mini_rt->ray->origin->z = mini_rt->cam->orig->z;
	mini_rt->cam = mini_rt->cam_list->content;
	mini_rt->cam->up->x = 0;
	mini_rt->cam->up->y = -1;
	mini_rt->cam->up->z = 0;
	mini_rt->cam->right = vec_cross_prod(unit_vector(mini_rt->cam->dir), mini_rt->cam->up);
	mini_rt->cam->up = vec_cross_prod(mini_rt->cam->right, unit_vector(mini_rt->cam->dir));
	j = 0;
	k = 2;
	while (j < mini_rt->res->y)
	{
		i = 0;
		while (i < mini_rt->res->x)
		{
			update_ray(mini_rt, ((i / (double)mini_rt->res->x) - 0.5), ((j / (double)mini_rt->res->y) - 0.5));
			// /* normalized vector ! */
			// ray->direction = unit_vector(ray->direction);
			display_elements(mini_rt, mini_rt->ray, k, j);
			i++;
			k+= 4;
		}
		j++;
	}
	return (0);
}
