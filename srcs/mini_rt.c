/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/22 13:23:39 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*mini_rt;

	if (params_check(ac, av) == 0)
	{
		if (!(mini_rt = initialize_scene()))
			return (-1);
		read_and_parse(av[1], mini_rt);
		mini_rt->window->win_ptr = mlx_new_window(
				mini_rt->mlx_ptr,
				mini_rt->window->res_x,
				mini_rt->window->res_y,
				mini_rt->window->title);
		set_img(mini_rt);
		mlx_put_image_to_window(mini_rt->mlx_ptr,
				mini_rt->window->win_ptr,
				mini_rt->window->img_ptr,
				0,0);
		mlx_loop(mini_rt->mlx_ptr);
	}
	return (0);
}
