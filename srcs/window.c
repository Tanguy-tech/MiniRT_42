/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/10 14:38:46 by tbillon          ###   ########lyon.fr   */
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

int	set_img(t_scene	*rt)
{
	if (!(rt->img->ptr = mlx_new_image(rt->mlx_ptr,
				rt->res->x,
				rt->res->y)))
		return (error_code(4, NULL));
	if (!(rt->img->data = mlx_get_data_addr(rt->img->ptr,
				&rt->img->bpp,
				&rt->res->x,
				&rt->img->endian)))
		return (error_code(4, NULL));
	rt->res->x /= 4;
	double i;
	double j;
	int k;
	
	gen_ray(rt);
	rt->cam = rt->cam_list->content;
	rt->res->ratio = (1.0 * rt->res->y) / (1.0 * rt->res->x);
	j = 0;
	k = 2;
	while (j < rt->res->y)
	{
		i = 0;
		while (i < rt->res->x)
		{
			update_ray(rt, i/rt->res->x , j/rt->res->x);
			display_elements(rt, rt->ray, k, j);
			i++;
			k+= 4;
		}
		j++;
	}
	return (0);
}
