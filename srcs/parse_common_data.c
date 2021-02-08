/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:46:48 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 15:26:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */
int		parse_resolution(char *str, char *file_path, char *type, t_scene *mini_rt)
{
	char	*res_x_str;
	char	*res_y_str;
	char	**data;
	int		i;
	char	current_axis;
	
	i = 0;
	data = ft_split(str, " \t");
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->window->res_x = ft_atoi(data[0]);
		mini_rt->window->res_y = ft_atoi(data[1]);
		mini_rt->window->title = ft_strrchr(file_path, '/');
		ft_putstr("RESOLUTION DONE\n");
		return (1);
	}
	return (0);
	/*	- Check str format ->  Return 0) ERROR if invalid (cf subject)
		- initialise Resolution structure in the current scene 
		- fill structure with parsed data 
		- Return (-1) if something went wrong in a subfunction
		- Return (1) if all good */
}

/* PARSE AMBIANT LIGHT */
int		parse_ambiant_light_data(char *str, char *type, t_scene *mini_rt)
{
	int		i;
	char	**data;
		
	i = 0;
	data = ft_split(str, " \t");
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->amb_light->ratio = ft_atof(data[0]);
		mini_rt->amb_light->color->r = ft_atof(trunc_code(data[1], 0));
		mini_rt->amb_light->color->g = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->amb_light->color->b = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		ft_putstr("AMBIANT LIGHT DONE\n");
		return (1);
	}
	return (0);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise Ambiant light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE CAMERA POSTION */
int		parse_camera_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->cam->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->cam->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->cam->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->cam->orientation->x = ft_atof(trunc_code(data[1], 0));
		mini_rt->cam->orientation->y = ft_atof(trunc_code(data[1], find_next_code(data[1]) + 1));
		mini_rt->cam->orientation->z = ft_atof(trunc_code(data[1], (ft_strlen(trunc_code(data[1], 0)) + ft_strlen(trunc_code(data[1], find_next_code(data[1]) + 1)) + 2)));
		mini_rt->cam->fov = ft_atof(data[2]);
		ft_putstr("CAMERA DONE\n");
		return (1);
	}
	return (0);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise camera structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE LIGHT INFORMATIONS */
int		parse_light_data(char *str, char *type, t_scene *mini_rt)
{
	char	**data;

	data = ft_split(str, " \t");
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->light->x = ft_atof(trunc_code(data[0], 0));
		mini_rt->light->y = ft_atof(trunc_code(data[0], find_next_code(data[0]) + 1));
		mini_rt->light->z = ft_atof(trunc_code(data[0], (ft_strlen(trunc_code(data[0], 0)) + ft_strlen(trunc_code(data[0], find_next_code(data[0]) + 1)) + 2)));
		mini_rt->light->light_ratio = ft_atof(data[1]);
		mini_rt->light->color->r = ft_atof(trunc_code(data[2], 0));
		mini_rt->light->color->g = ft_atof(trunc_code(data[2], find_next_code(data[2]) + 1));
		mini_rt->light->color->b = ft_atof(trunc_code(data[2], (ft_strlen(trunc_code(data[2], 0)) + ft_strlen(trunc_code(data[2], find_next_code(data[2]) + 1)) + 2))); 
		ft_putstr("LIGHT DONE\n");
		return (1);
	}
	return (0);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}
