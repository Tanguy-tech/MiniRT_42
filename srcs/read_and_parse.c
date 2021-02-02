/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:00:26 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 16:07:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */
int		parse_resolution(char *str)
{
	/*	- Check str format ->  Return (-1) ERROR if invalid (cf subject)
		- initialise Resolution structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE AMBIANT LIGHT */
int		parse_ambiant_light_data(char *str)
{
	/*	- Check str format ->  Return (-1) ERROR if invalid (cf subject)
		- initialise Ambiant light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE CAMERA POSTION */
int		parse_camera_data(char *str)
{
	/*	- Check str format ->  Return (-1) ERROR if invalid (cf subject)
		- initialise camera structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSE LIGHT INFORMATIONS */
int		parse_light_data(char *str)
{
	/*	- Check str format ->  Return (-1) ERROR if invalid (cf subject)
		- initialise light structure in the current scene 
		- fill structure with parsed data 
		- Return (1) if all good */
}

/* PARSER ENGINE */
int		parser_engine(char *line)
{
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
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	/* PARSER ENGINE GOES HERE for the last line */
	ft_putstr(line);
	free(line);
	line = NULL;
	return (0);
}
