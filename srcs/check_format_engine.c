/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_engine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:35:30 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:25:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_format_engine(char *str, char *type, char **data)
{
	if (ft_strncmp(type, "R", ft_strlen(type)) == 0)
		return (check_res_format(str, type, data));
	if (ft_strncmp(type, "A", ft_strlen(type)) == 0)
		return (check_amb_format(str, type, data));
	if (ft_strncmp(type, "c", ft_strlen(type)) == 0)
		return (check_c_format(str, type, data));
	if (ft_strncmp(type, "l", ft_strlen(type)) == 0)
		return (check_l_format(str, type, data));
	if (ft_strncmp(type, "sp", ft_strlen(type)) == 0)
		return (check_sphere_format(str, type, data));
	if (ft_strncmp(type, "pl", ft_strlen(type)) == 0)
		return (check_plan_format(str, type, data));
	if (ft_strncmp(type, "sq", ft_strlen(type)) == 0)
		return (check_square_format(str, type, data));
	if (ft_strncmp(type, "cy", ft_strlen(type)) == 0)
		return (check_cylinder_format(str, type, data));
	return (0);
}
