/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:46:48 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 09:59:15 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_resolution(char *str, char *file_path, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->window->res_x = ft_atoi(data[0]);
		mini_rt->window->res_y = ft_atoi(data[1]);
		mini_rt->window->title = ft_strrchr(file_path, '/');
		ft_putstr("RESOLUTION DONE\n");
		return (1);
	}
	return (0);
}

int	parse_ambiant_light_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;
	char	**color;

	data = ft_split(str, " \t");
	color = ft_split(data[1], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->amb_light->ratio = ft_atof(data[0]);
		mini_rt->amb_light->color->r = ft_atof(color[0]);
		mini_rt->amb_light->color->g = ft_atof(color[1]);
		mini_rt->amb_light->color->b = ft_atof(color[2]);
		ft_putstr("AMBIANT LIGHT DONE\n");
		return (1);
	}
	return (0);
}

int	parse_camera_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;
	char	**coord;
	char	**orientation;

	data = ft_split(str, " \t");
	coord = ft_split(data[0], ",");
	orientation = ft_split(data[1], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->cam->x = ft_atof(coord[0]);
		mini_rt->cam->y = ft_atof(coord[1]);
		mini_rt->cam->z = ft_atof(coord[2]);
		mini_rt->cam->orientation->x = ft_atof(orientation[0]);
		mini_rt->cam->orientation->y = ft_atof(orientation[1]);
		mini_rt->cam->orientation->z = ft_atof(orientation[2]);
		mini_rt->cam->fov = ft_atof(data[2]);
		ft_putstr("CAMERA DONE\n");
		return (1);
	}
	return (0);
}

int	parse_light_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;
	char	**coord;
	char	**color;

	data = ft_split(str, " \t");
	coord = ft_split(data[0], ",");
	color = ft_split(data[2], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->light->x = ft_atof(coord[0]);
		mini_rt->light->y = ft_atof(coord[1]);
		mini_rt->light->z = ft_atof(coord[2]);
		mini_rt->light->light_ratio = ft_atof(data[1]);
		mini_rt->light->color->r = ft_atof(color[0]);
		mini_rt->light->color->g = ft_atof(color[1]);
		mini_rt->light->color->b = ft_atof(color[2]);
		ft_putstr("LIGHT DONE\n");
		return (1);
	}
	return (0);
}
