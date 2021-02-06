/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:40:13 by tbillon          ###   ########lyon.fr   */
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
		mlx_loop(mini_rt->mlx_ptr);	/* - Return ERROR if any error occur while executing the parsing and checking functions */
	}
	return (0);
}
