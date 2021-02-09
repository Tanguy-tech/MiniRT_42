/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 08:37:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*mini_rt;

	if (params_check(ac, av) == 0) /* if no errors detected, then open and read file.rt */
	{
		if (!(mini_rt = initialize_scene())) /* initialize strcuture s_scene */
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
		dprintf(1, "mini_rt->light->x= %f\n", mini_rt->light->x);
		dprintf(1, "mini_rt->light->y= %f\n", mini_rt->light->y);
		dprintf(1, "mini_rt->light->z= %f\n", mini_rt->light->z);
		dprintf(1, "mini_rt->light->light_ratio= %f\n", mini_rt->light->light_ratio);
		dprintf(1, "mini_rt->light->color->r = %f\n", mini_rt->light->color->r);
		dprintf(1, "mini_rt->light->color->g = %f\n", mini_rt->light->color->g);
		dprintf(1, "mini_rt->light->color->b = %f\n", mini_rt->light->color->b);
		dprintf(1, "mini_rt->sp->origin_coord->x = %f\n", mini_rt->sp->origin_coord->x);
		dprintf(1, "mini_rt->sp->origin_coord->y = %f\n", mini_rt->sp->origin_coord->y);
		dprintf(1, "mini_rt->sp->origin_coord->z = %f\n", mini_rt->sp->origin_coord->z);
		dprintf(1, "mini_rt->sp->diam = %f\n", mini_rt->sp->diam);
		dprintf(1, "mini_rt->sp->color->r = %f\n", mini_rt->sp->color->r);
		dprintf(1, "mini_rt->sp->color->g = %f\n", mini_rt->sp->color->g);
		dprintf(1, "mini_rt->sp->color->b = %f\n", mini_rt->sp->color->b);
		dprintf(1, "mini_rt->pl->coord->x = %f\n", mini_rt->pl->coord->x);
		dprintf(1, "mini_rt->pl->coord->y = %f\n", mini_rt->pl->coord->y);
		dprintf(1, "mini_rt->pl->coord->z = %f\n", mini_rt->pl->coord->z);
		dprintf(1, "mini_rt->pl->orientation->x = %f\n", mini_rt->pl->orientation->x);
		dprintf(1, "mini_rt->pl->orientation->y = %f\n", mini_rt->pl->orientation->y);
		dprintf(1, "mini_rt->pl->orientation->z = %f\n", mini_rt->pl->orientation->z);
		dprintf(1, "mini_rt->pl->color->r = %f\n", mini_rt->pl->color->r);
		dprintf(1, "mini_rt->pl->color->g = %f\n", mini_rt->pl->color->g);
		dprintf(1, "mini_rt->pl->color->b = %f\n", mini_rt->pl->color->b);
		dprintf(1, "mini_rt->sq->coord->x = %f\n", mini_rt->sq->coord->x);
		dprintf(1, "mini_rt->sq->coord->y = %f\n", mini_rt->sq->coord->y);
		dprintf(1, "mini_rt->sq->coord->z = %f\n", mini_rt->sq->coord->z);
		dprintf(1, "mini_rt->sq->orientation->x = %f\n", mini_rt->sq->orientation->x);
		dprintf(1, "mini_rt->sq->orientation->y = %f\n", mini_rt->sq->orientation->y);
		dprintf(1, "mini_rt->sq->orientation->z = %f\n", mini_rt->sq->orientation->z);
		dprintf(1, "mini_rt->sq->height = %f\n", mini_rt->sq->height);
		dprintf(1, "mini_rt->sq->color->r = %f\n", mini_rt->sq->color->r);
		dprintf(1, "mini_rt->sq->color->g = %f\n", mini_rt->sq->color->g);
		dprintf(1, "mini_rt->sq->color->b = %f\n", mini_rt->sq->color->b);
		dprintf(1, "mini_rt->cy->origin_coord->x = %f\n", mini_rt->cy->origin_coord->x);
		dprintf(1, "mini_rt->cy->origin_coord->y = %f\n", mini_rt->cy->origin_coord->y);
		dprintf(1, "mini_rt->cy->origin_coord->z = %f\n", mini_rt->cy->origin_coord->z);
		dprintf(1, "mini_rt->cy->orientation->x = %f\n", mini_rt->cy->orientation->x);
		dprintf(1, "mini_rt->cy->orientation->y = %f\n", mini_rt->cy->orientation->y);
		dprintf(1, "mini_rt->cy->orientation->z = %f\n", mini_rt->cy->orientation->z);
		dprintf(1, "mini_rt->cy->diam = %f\n", mini_rt->cy->diam);
		dprintf(1, "mini_rt->cy->height = %f\n", mini_rt->cy->height);
		dprintf(1, "mini_rt->cy->color->r = %f\n", mini_rt->cy->color->r);
		dprintf(1, "mini_rt->cy->color->g = %f\n", mini_rt->cy->color->g);
		dprintf(1, "mini_rt->cy->color->b = %f\n", mini_rt->cy->color->b);
		dprintf(1, "mini_rt->tr->first_coord->x = %f\n", mini_rt->tr->first_coord->x);
		dprintf(1, "mini_rt->tr->first_coord->y = %f\n", mini_rt->tr->first_coord->y);
		dprintf(1, "mini_rt->tr->first_coord->z = %f\n", mini_rt->tr->first_coord->z);
		dprintf(1, "mini_rt->tr->sec_coord->x = %f\n", mini_rt->tr->sec_coord->x);
		dprintf(1, "mini_rt->tr->sec_coord->y = %f\n", mini_rt->tr->sec_coord->y);
		dprintf(1, "mini_rt->tr->sec_coord->z = %f\n", mini_rt->tr->sec_coord->z);
		dprintf(1, "mini_rt->tr->third_coord->x = %f\n", mini_rt->tr->third_coord->x);
		dprintf(1, "mini_rt->tr->third_coord->y = %f\n", mini_rt->tr->third_coord->y);
		dprintf(1, "mini_rt->tr->third_coord->z = %f\n", mini_rt->tr->third_coord->z);
		dprintf(1, "mini_rt->tr->color->r = %f\n", mini_rt->tr->color->r);
		dprintf(1, "mini_rt->tr->color->g = %f\n", mini_rt->tr->color->g);
		dprintf(1, "mini_rt->tr->color->b = %f\n", mini_rt->tr->color->b);
		mlx_loop(mini_rt->mlx_ptr);	/* - Return ERROR if any error occur while executing the parsing and checking functions */
	}
	return (0);
}
