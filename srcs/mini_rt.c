/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 13:48:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_win(int keycode, t_scene *rt)
{
	if (keycode == 53)
	{
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_cross(t_scene *rt)
{
	mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
	exit(0);
}

void	create_window(t_scene *rt)
{
	rt->win_ptr = mlx_new_window(
			rt->mlx_ptr,
			rt->res.x,
			rt->res.y,
			rt->title);
	set_img(rt);
	create_thread(rt);
	mlx_put_image_to_window(rt->mlx_ptr,
		rt->win_ptr,
		rt->img->ptr,
		0, 0);
	mlx_hook(rt->win_ptr, 2, 1L << 0, close_win, rt);
	mlx_hook(rt->win_ptr, 17, 1L << 17, close_cross, rt);
	mlx_loop(rt->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_scene	*rt;

	if (params_check(ac, av) == 0)
	{
		rt = initialize_scene();
		if (!(rt))
			return (-1);
		read_and_parse(av[1], rt);
		create_window(rt);
	}
	return (0);
}
