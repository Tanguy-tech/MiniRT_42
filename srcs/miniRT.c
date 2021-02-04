/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 13:19:30 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	s_scene	*mini_rt;

	/* initialize strcuture s_scene */

	if (params_check(ac, av) == 0) /* if no errors detected, then open and read file.rt */
	{
		read_and_parse(av[1], mini_rt); /* - Function GNL that open read and parse the information from *.rt file */
		//mlx_loop(mini_rt->mlx_ptr);	/* - Return ERROR if any error occur while executing the parsing and checking functions */
	}
	return (0);
}
