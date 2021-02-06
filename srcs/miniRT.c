/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:41:16 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*mini_rt;

	/* initialize strcuture s_scene */

	if (params_check(ac, av) == 0) /* if no errors detected, then open and read file.rt */
	{
		if (!(mini_rt = initialize_scene()))
			return (-1);
		read_and_parse(av[1], mini_rt); /* - Function GNL that open read and parse the information from *.rt file */
		mini_rt->window->win_ptr = mlx_new_window(mini_rt->mlx_ptr, mini_rt->window->res_x, mini_rt->window->res_y, mini_rt->window->title);
		dprintf(1, "mini_rt->window->res_x = %d\n", mini_rt->window->res_x);
		dprintf(1, "mini_rt->window->res_y = %d\n", mini_rt->window->res_y);
		dprintf(1, "mini_rt->window->title = %s\n", mini_rt->window->title);
		dprintf(1, "mini_rt->amb_light->color->r = %f\n", mini_rt->amb_light->color->r);
		dprintf(1, "mini_rt->amb_light->color->g = %f\n", mini_rt->amb_light->color->g);
		dprintf(1, "mini_rt->amb_light->color->b = %f\n", mini_rt->amb_light->color->b);
		dprintf(1, "mini_rt->amb_light->ratio = %f\n", mini_rt->amb_light->ratio);
		dprintf(1, "mini_rt->cam->x = %f\n", mini_rt->cam->x);
		dprintf(1, "mini_rt->cam->y = %f\n", mini_rt->cam->y);
		dprintf(1, "mini_rt->cam->z = %f\n", mini_rt->cam->z);
		dprintf(1, "mini_rt->cam->orientation->x = %f\n", mini_rt->cam->orientation->x);
		dprintf(1, "mini_rt->cam->orientation->y = %f\n", mini_rt->cam->orientation->y);
		dprintf(1, "mini_rt->cam->orientation->z = %f\n", mini_rt->cam->orientation->z);
		dprintf(1, "mini_rt->cam->fov = %f\n", mini_rt->cam->fov);
		mlx_loop(mini_rt->mlx_ptr);	/* - Return ERROR if any error occur while executing the parsing and checking functions */
	}
	return (0);
}
