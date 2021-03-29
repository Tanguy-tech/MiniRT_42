/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:46:48 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 08:53:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parse_res(char *str, char *path, t_scene *mini_rt, char **data)
{
	if (check_format_engine(str, data[0], data) == 1)
	{
		mini_rt->res.x = ft_atoi(data[1]);
		mini_rt->res.y = ft_atoi(data[2]);
		mini_rt->res.orig_x = mini_rt->res.x;
		mini_rt->res.ratio = (1.0 * mini_rt->res.y) / (1.0 * mini_rt->res.x);
		mini_rt->title = ft_strrchr(path, '/');
		return (1);
	}
	return (0);
}

int	parse_amb_light_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**color;

	color = ft_split(data[2], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->amb_light->ratio = ft_atof(data[1]);
		mini_rt->amb_light->color->r = ft_atof(color[0]);
		mini_rt->amb_light->color->g = ft_atof(color[1]);
		mini_rt->amb_light->color->b = ft_atof(color[2]);
		return (1);
	}
	return (0);
}

int	parse_camera_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**dir;

	coord = ft_split(data[1], ",");
	dir = ft_split(data[2], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->cam.orig.x = ft_atof(coord[0]);
		mini_rt->cam.orig.y = ft_atof(coord[1]);
		mini_rt->cam.orig.z = ft_atof(coord[2]);
		mini_rt->cam.dir.x = ft_atof(dir[0]);
		mini_rt->cam.dir.y = ft_atof(dir[1]);
		mini_rt->cam.dir.z = ft_atof(dir[2]);
		mini_rt->cam.fov = ft_atof(data[3]);
		return (1);
	}
	return (0);
}

int	parse_light_data(char *str, char *type, t_scene *mini_rt, char **data)
{
	char	**coord;
	char	**color;

	coord = ft_split(data[1], ",");
	color = ft_split(data[3], ",");
	if (check_format_engine(str, type, data) == 1)
	{
		mini_rt->light->orig->x = ft_atof(coord[0]);
		mini_rt->light->orig->y = ft_atof(coord[1]);
		mini_rt->light->orig->z = ft_atof(coord[2]);
		mini_rt->light->ratio = ft_atof(data[2]);
		mini_rt->light->color->r = ft_atof(color[0]);
		mini_rt->light->color->g = ft_atof(color[1]);
		mini_rt->light->color->b = ft_atof(color[2]);
		return (1);
	}
	return (0);
}
