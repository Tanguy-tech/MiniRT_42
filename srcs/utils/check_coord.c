/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:52:33 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:00:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*catch_coordinates(char *str)
{
	int		i;
	char	*coord;

	i = 0;
	coord = ft_calloc(sizeof(char), 2);
	if (!(coord))
		return (NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-'
			|| str[i] == '.' || str[i] == ',')
		{
			coord = str_add_char(coord, str[i]);
			if (!(coord))
				return (NULL);
		}
		if (ft_iswhitespace(str[i + 1]) && coord[1] != '\0')
			break ;
		i++;
	}
	return (coord);
}

int	check_coordinates(char *str)
{
	int	i;

	i = 0;
	if (count_double(str) >= 0 && count_double(str) <= 3)
		if (count_comma_format(str) == 2)
			return (1);
	return (0);
}
