/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:00:26 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 10:42:31 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */
int		parse_resolution(char *str)
{
	ft_putstr("RESOLUTION DONE\n");
	return (1);
	/*	- Check str format ->  Return 0) ERROR if invalid (cf subject)
		- initialise Resolution structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE AMBIANT LIGHT */
int		parse_ambiant_light_data(char *str)
{
	ft_putstr("AMBIANT LIGHT DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise Ambiant light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE CAMERA POSTION */
int		parse_camera_data(char *str)
{
	ft_putstr("CAMER DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise camera structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE LIGHT INFORMATIONS */
int		parse_light_data(char *str)
{
	ft_putstr("LIGHT DONE\n");
	return (1);
	/*	- Check str format ->  Return (0) ERROR if invalid (cf subject)
		- initialise light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSER ENGINE */
int		parser_engine(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			return (parse_resolution(line + 1 + i));
		if (line[i] == 'A')
			return (parse_ambiant_light_data(line + 1 + i));
		if (line[i] == 'c')
			return (parse_camera_data(line + 1 + i));
		if (line[i] == 'l')
			return (parse_light_data(line + 1 + i));
		if (line[i] == 's' && line[i + 1] == 'p')
			return (parse_sphere_data(line + 2 + i));
		if (line[i] == 's' && line[i + 1] == 'q')
			return (parse_square_data(line + 2 + i));
		if (line[i] == 't' && line[i + 1] == 'r')
			return (parse_triangle_data(line + 2 + i));
		if (line[i] == 'c' && line[i + 1] == 'y')
			return (parse_cylinder_data(line + 2 + i));
		if (line[i] == 'p' && line[i + 1] == 'l')
			return (parse_plan_data(line + 2 + i));
		else
			i++;
	}
	return (-1);
	/* 	- redirect to the correct function refering to the idientifier (R A c l sp sq tr cy pl).
		- Return (1) if all good
		- Return (0) if an ERROR is encountered in a sub-function (parse light camera etc..)
		- Return (-1) -> ERROR if none of thoses is encountered  (cf subject) */
}

int		read_and_parse(char *file_path)
{
	int		fd;
	char	*line;
	
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0) /* Function that open and read the file */
	{
		/* PARSER ENGINE GOES HERE */
		parser_engine(line);
		free(line);
		line = NULL;
	}
	/* PARSER ENGINE GOES HERE for the last line */
	parser_engine(line);
	free(line);
	line = NULL;
	return (0);
}
