/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 14:31:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_window	*initialize_window(void)
{
	t_window	*new_window;

	if (!(new_window = ft_calloc(sizeof(t_window), 1)))
		return (NULL);
	new_window->res_x = 0;
	new_window->res_y = 0;
	new_window->title = "\0";
	new_window->bit_per_pixel = 0;
	new_window->size_line = 0;
	new_window->endian = 0;
	new_window->data = "\0";
	return (new_window);
}

int	set_img(t_scene	*mini_rt)
{
	if (!(mini_rt->window->img_ptr = mlx_new_image(mini_rt->mlx_ptr,
				mini_rt->window->res_x,
				mini_rt->window->res_y)))
		return (error_code(4, NULL));
	if (!(mini_rt->window->data = mlx_get_data_addr(mini_rt->window->img_ptr,
				mini_rt->window->bit_per_pixel,
				mini_rt->window->size_line,
				mini_rt->window->endian)))
		return (error_code(4, NULL));
}
