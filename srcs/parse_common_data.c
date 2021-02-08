/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:46:48 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 12:18:42 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */
int		parse_resolution(char *str, char *file_path, char *type, t_scene *mini_rt)
{
	char	*res_x_str;
	char	*res_y_str;
	int		i;
	char	current_axis;
	
	i = 0;
	if (check_format_engine(str, type) == 1)
	{
		if (!(res_x_str = ft_calloc(1, sizeof(char))))
			return (-1);
		if (!(res_y_str = ft_calloc(1, sizeof(char))))
			return (-1);
		current_axis = 'N';
		while (str[i])
		{
			if (str[i] >= 48 && str[i] <= 57 && str[i])
			{
				if (current_axis == 'N' || current_axis == 'X')
				{
					current_axis = 'X';
					if (!(res_x_str = str_add_char(res_x_str, str[i])))
						return (-1);
				}
				else
					if (!(res_y_str = str_add_char(res_y_str, str[i])))
						return (-1);
			}
			if (current_axis == 'X' && (ft_iswhitespace(str[i])))
				current_axis = 'Y';
			i++;
		}
		mini_rt->window->res_x = ft_atoi(res_x_str);
		mini_rt->window->res_y = ft_atoi(res_y_str);
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
	int				i;
	char			*ratio_str;
	double			ratio;
		
	i = 0;
	ratio_str = get_double(str, 0);
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->amb_light->ratio = ft_atof(ratio_str);
		mini_rt->amb_light->color->r = ft_atof(trunc_code(get_rgb_code(str), 0));
		mini_rt->amb_light->color->g = ft_atof(trunc_code(get_rgb_code(str), find_next_code(get_rgb_code(str)) + 1));
		mini_rt->amb_light->color->b = ft_atof(trunc_code(get_rgb_code(str), find_next_code(get_rgb_code(str)) + 1 + find_next_code(get_rgb_code(str)) + 1));
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
	char *coord_str;
	char *or_str;

	coord_str = catch_coordinates(str);
	or_str = catch_coordinates(str + ft_strlen(coord_str) + 1);
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->cam->x = ft_atof(trunc_code(coord_str, 0));
		mini_rt->cam->y = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1));
		mini_rt->cam->z = ft_atof(trunc_code(get_rgb_code(coord_str), find_next_code(get_rgb_code(coord_str)) + 1 + find_next_code(get_rgb_code(coord_str)) + 1));
		mini_rt->cam->orientation->x = ft_atof(trunc_code(or_str, 0));
		mini_rt->cam->orientation->y = ft_atof(trunc_code(or_str, find_next_code(or_str) + 1));
		mini_rt->cam->orientation->z = ft_atof(trunc_code(get_rgb_code(or_str), find_next_code(get_rgb_code(or_str)) + 1 + find_next_code(get_rgb_code(or_str)) + 1));
		mini_rt->cam->fov = get_angle(str);
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
	char	*coord_str;
	char	*ratio_str;
	char	*colors_str;
	int		i;

	coord_str = catch_coordinates(str);
	colors_str = get_rgb_code(str);
	i = ft_strlen(coord_str) + 2;
	ratio_str = get_double(str, i);
	if (check_format_engine(str, type) == 1)
	{
		mini_rt->light->x = ft_atof(trunc_code(coord_str, 0));
		mini_rt->light->y = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1));
		mini_rt->light->z = ft_atof(trunc_code(coord_str, find_next_code(coord_str) + 1 + find_next_code(coord_str) + 1));
		mini_rt->light->light_ratio = ft_atof(ratio_str);
		mini_rt->light->color->r = ft_atof(trunc_code(colors_str, 0));
		mini_rt->light->color->g = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1));
		mini_rt->light->color->b = ft_atof(trunc_code(colors_str, find_next_code(colors_str) + 1 + find_next_code(colors_str))); 
		ft_putstr("LIGHT DONE\n");
		return (1);
	}
	return (0);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}
