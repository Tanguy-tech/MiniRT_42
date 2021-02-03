/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_common_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:46:48 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 14:20:27 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */
int		parse_resolution(char *str, char *file_path, char *type)
{
	char	*res_x_str;
	char	*res_y_str;
	int		i;
	char	current_axis;
	s_window	*window;
	
	i = 0;
	if (check_format(str, type) == 1)
	{
		if (!(res_x_str = ft_calloc(1, sizeof(char))))
			return (-1);
		if (!(res_y_str = ft_calloc(1, sizeof(char))))
			return (-1);
		current_axis = 'N';
		if (!(window = initialize_window()))
			return (-1);
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
			if (current_axis == 'X' && (str[i] == 32 || str[i] == 9))
				current_axis = 'Y';
			i++;
		}
	window->res_x = ft_atoi(res_x_str);
	window->res_y = ft_atoi(res_y_str);
	window->title = ft_strrchr(file_path, '/');
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
int		parse_ambiant_light_data(char *str, char *type)
{
	ft_putstr("AMBIANT LIGHT DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise Ambiant light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE CAMERA POSTION */
int		parse_camera_data(char *str, char *type)
{
	ft_putstr("CAMERA DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise camera structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE LIGHT INFORMATIONS */
int		parse_light_data(char *str, char *type)
{
	ft_putstr("LIGHT DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}
