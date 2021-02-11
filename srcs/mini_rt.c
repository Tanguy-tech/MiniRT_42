/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 11:15:56 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*mini_rt;
	t_mlx	*my_mlx;

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
		mlx_loop(mini_rt->mlx_ptr);
	}
	return (0);
}
