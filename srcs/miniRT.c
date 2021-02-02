/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:23 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 16:21:25 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		main(int ac, char **av)
{
	if (params_check(ac, av) == 0) /* if no errors detected, then open and read file.rt */
	{
		read_and_parse(av[1]); /* - Function GNL that open read and parse the information from *.rt file
								  - Return ERROR if any error occur while executing the parsing and checking functions */
	}
	return (0);
}