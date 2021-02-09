/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:32:29 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 12:48:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	error_code(int error_code, char *name)
{
	if (error_code == 1)
	{
		ft_putstr("ERROR\nWrong number of arguments!");
		ft_putstr(" Missing scene file (type *.rt)\n");
	}
	if (error_code == 2)
	{
		ft_putstr("ERROR\nWrong exec name or file format detected.");
		ft_putstr("First argument must be ./miniRT, ");
		ft_putstr("and second argument must be a *.rt file\n");
	}
	if (error_code == 3)
	{
		ft_putstr("ERROR\nWrong element format in *.rt file.");
		ft_putstr(" check again at -> ");
		ft_putstr(name);
		ft_putstr(" format\n");
	}
	return (0);
}

int	params_check(int ac, char **av)
{
	char	*file;

	if (ac < 2)
	{
		error_code(1, NULL);
		return (1);
	}
	else if (ac == 2)
	{
		file = ft_strnstr(av[1], ".rt", ft_strlen(av[1]));
		if ((ft_strncmp(av[0], "./miniRT", ft_strlen(av[0]))) != 0)
		{
			error_code(2, NULL);
			return (1);
		}
		if ((ft_strncmp(file, ".rt", ft_strlen(file))) != 0)
		{
			error_code(2, NULL);
			return (1);
		}
	}
	return (0);
}
