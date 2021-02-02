/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:32:29 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 09:53:45 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		error_code(int error_code)
{
	if (error_code == 1)
		ft_putstr("ERROR Wrong number of arguments! Missing scene file (type *.rt)\n");
	if (error_code == 2)
		ft_putstr("ERROR Wrong exec name or file format detected. First argument must be ./miniRT, and second argument must be a *.rt file");
	return (0);
}

int		errors_check(int ac, char **av)
{
	char *file;

	if (ac < 2)
	{
		error_code(1);
		return (1);
	}
	else if (ac == 2)
	{
		file = ft_strnstr(av[1], ".rt", ft_strlen(av[1]));
		if (((ft_strncmp(av[0], "./miniRT", ft_strlen(av[0]))) != 0) || (ft_strncmp(file, ".rt", ft_strlen(file))) != 0)
		{
			error_code(2);
			return (1);
		}
	}
	return (0);
}