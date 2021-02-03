/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rgb_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:10:24 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 16:27:27 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	count_rgb_format(char *str)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int	get_rgb_code(char *str)
{
	int 	i;
	int		j;
	char	*rgb_code;

	i = 0;
	j = 0;
	if (!(rgb_code = ft_calloc(sizeof(char), 12)))
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ',')
		{
			if ((ft_isdigit(str[i + 1]) || str[i + 1] == ',') && count_double(str + i) == 0)
			{
				rgb_code[j] = str[i];
				j++;
			}
			if (str[i + 1] == '\0')
				rgb_code[j] = str[i];
		}
		i++;
	}
	return (count_rgb_format(rgb_code));
}
