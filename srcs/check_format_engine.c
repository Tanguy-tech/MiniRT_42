/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_engine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:35:30 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 14:19:34 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		check_format_engine(char *str, char *type)
{
	/* Check the str format for the parsing process */
	if (ft_strncmp(type, "R", ft_strlen(type)) == 0)
		return (check_R_format(str, type));
	if (ft_strncmp(type, "A", ft_strlen(type)) == 0)
		return (check_A_format(str, type));
	if (ft_strncmp(type, "c", ft_strlen(type)) == 0)
		return (check_c_format(str, type));
	if (ft_strncmp(type, "l", ft_strlen(type)) == 0)
		return (check_l_format(str, type));
	if (ft_strncmp(type, "sp", ft_strlen(type)) == 0)
		return (check_sphere_format(str, type));
	if (ft_strncmp(type, "pl", ft_strlen(type)) == 0)
		return (check_plan_format(str, type));
	if (ft_strncmp(type, "sq", ft_strlen(type)) == 0)
		return (check_square_format(str, type));
	if (ft_strncmp(type, "cy", ft_strlen(type)) == 0)
		return (check_cylinder_format(str, type));
	return (0);
}
