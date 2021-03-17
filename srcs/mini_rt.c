/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 14:50:02 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		close_win(int keycode, t_scene *vars)
{
	if (keycode == 53)
    	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	return (0);
}

void	create_window(t_scene *mini_rt)
{
	mini_rt->win_ptr = mlx_new_window(
				mini_rt->mlx_ptr,
				mini_rt->res->x,
				mini_rt->res->y,
				mini_rt->title);
		set_img(mini_rt);
		mlx_put_image_to_window(mini_rt->mlx_ptr,
				mini_rt->win_ptr,
				mini_rt->img->ptr,
				0,0);
		mlx_hook(mini_rt->win_ptr, 2, 1L<<0, close_win, mini_rt);
		mlx_loop(mini_rt->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_scene	*mini_rt;

	if (params_check(ac, av) == 0)
	{
		if (!(mini_rt = initialize_scene()))
			return (-1);
		read_and_parse(av[1], mini_rt);
		create_window(mini_rt);
	}
	return (0);
}
