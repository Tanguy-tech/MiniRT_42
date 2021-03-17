/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 16:51:24 by tbillon          ###   ########lyon.fr   */
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
	create_thread(rt);
	return (0);
}
