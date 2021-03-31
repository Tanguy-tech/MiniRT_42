/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/31 16:41:28 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/vectors.h"

void	display_elements(t_thread *th, int index)
{
	t_list	*tmp;
	tmp = th->rt.elem_list;
	while(tmp)
	{
		th->rt.element = *tmp->content;
		if (th->rt.element.id == 1)
			put_sphere(th, index);
		if (th->rt.element.id == 2)
			put_plan(th, index);
		if (th->rt.element.id == 3)
			put_square(th, index);
		// if (th->rt.element.id == 4)
		// 	put_cylinder(th, index);
		// if (th->rt.element.id == 5)
		tmp = tmp->next;
	}
}

int	set_img(t_scene	*rt)
{
	if (!(rt->img->ptr = mlx_new_image(rt->mlx_ptr,
				rt->res.x,
				rt->res.y)))
		return (error_code(4, NULL));
	if (!(rt->img->data = mlx_get_data_addr(rt->img->ptr,
				&rt->img->bpp,
				&rt->res.x,
				&rt->img->endian)))
		return (error_code(4, NULL));
	rt->res.x /= 4;
	return (0);
}
