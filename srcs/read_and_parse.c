/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:00:26 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 13:50:18 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSER ENGINE */
int		parser_engine(char *line, char *file_path, t_scene *mini_rt)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			return (parse_resolution(line + 1 + i, file_path, "R", mini_rt));
		if (line[i] == 'A')
			return (parse_ambiant_light_data(line + 1 + i, "A", mini_rt));
		if (line[i] == 'c')
			return (parse_camera_data(line + 1 + i, "c", mini_rt));
		if (line[i] == 'l')
			return (parse_light_data(line + 1 + i, "l", mini_rt));
		if (line[i] == 's' && line[i + 1] == 'p')
			return (parse_sphere_data(line + 2 + i, "sp", mini_rt));
		if (line[i] == 's' && line[i + 1] == 'q')
			return (parse_square_data(line + 2 + i, "sq", mini_rt));
		if (line[i] == 't' && line[i + 1] == 'r')
			return (parse_triangle_data(line + 2 + i, "tr", mini_rt));
		if (line[i] == 'c' && line[i + 1] == 'y')
			return (parse_cylinder_data(line + 2 + i, "cy", mini_rt));
		if (line[i] == 'p' && line[i + 1] == 'l')
			return (parse_plan_data(line + 2 + i, "pl", mini_rt));
		else
			i++;
	}
	return (-1);
	/* 	- redirect to the correct function refering to the idientifier (R A c l sp sq tr cy pl).
		- Return (1) if all good
		- Return (0) if an ERROR is encountered in a sub-function (parse light camera etc..)
		- Return (-1) -> ERROR if none of thoses is encountered  (cf subject) */
}

int		read_and_parse(char *file_path, t_scene *mini_rt)
{
	int		fd;
	char	*line;
	
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0) /* Function that open and read the file */
	{
		/* PARSER ENGINE GOES HERE */
		parser_engine(line, file_path, mini_rt);
		free(line);
		line = NULL;
	}
	/* PARSER ENGINE GOES HERE for the last line */
	parser_engine(line, file_path, mini_rt);
	free(line);
	line = NULL;
	return (0);
}
