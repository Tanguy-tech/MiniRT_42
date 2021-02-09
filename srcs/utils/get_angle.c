/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:33:27 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 10:21:20 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	get_angle(char *str)
{
	int		i;
	char	*angle_str;
	int		angle;

	i = ft_strlen(str) - 1;
	if (!(angle_str = ft_calloc(sizeof(char), 4)))
		return (-1);
	while (ft_isdigit(str[i]))
		i--;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (!(angle_str = str_add_char(angle_str, str[i])))
				return (-1);
		}
		i++;
	}
	angle = ft_atoi(angle_str);
	return (angle);
}
