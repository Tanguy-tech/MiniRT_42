/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_common_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 14:15:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* Check format for R type */
int	check_R_format(char *str)
{
	int count;
	int i;
	
	count = 0;
	i = 0;
	while (ft_isdigit(str[i]) || ft_iswhitespace(str[i]))
	{
		if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

/* Check format for A type */

/* Check format for c type */

/* Check format for l type */

int		check_format(char *str, char *type)
{
	/* Check the str format for the parsing process */
	if (ft_strncmp(type, "R", ft_strlen(type)) == 0)
		return (check_R_format(str));
	return (0);
}
