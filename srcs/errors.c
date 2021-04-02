/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:32:29 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:16:47 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	handle_error(char *msg, int code)
{
	printf("ERROR : %s\n", msg);
	exit (code);
}

int	params_check(int ac, char **av)
{
	char	*file;

	if (ac < 2)
	{
		return (handle_error(MISS_FILE, 1));
	}
	else if (ac == 2)
	{
		file = ft_strnstr(av[1], ".rt", ft_strlen(av[1]));
		if ((ft_strncmp(av[0], "./miniRT", ft_strlen(av[0]))) != 0)
			return (handle_error(EXEC_FORMAT, 0));
		if ((ft_strncmp(file, ".rt", ft_strlen(file))) != 0)
			return (handle_error(EXEC_FORMAT, 0));
	}
	return (0);
}
