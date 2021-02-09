/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:00:26 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 11:00:24 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	parser_engine(char *line, char *path, t_scene *mini_rt)
{
	int		i;
	char	**data;

	i = 0;
	data = ft_split(line, " \t");
	if (line[i] == 'R' || line[i] == 'A'
		|| (line[i] == 'c' && line[i + 1] != 'y') || line[i] == 'l')
	{
		return (parse_common(line, path, mini_rt, data));
	}
	else if ((line[i] == 's' && line[i + 1] == 'p')
		|| (line[i] == 'p' && line[i + 1] == 'l')
		|| (line[i] == 's' && line[i + 1] == 'q')
		|| (line[i] == 'c' && line[i + 1] == 'y')
		|| (line[i] == 't' && line[i + 1] == 'r'))
	{
		return (parse_objects(line, mini_rt, data));
	}
	return (-1);
}

int	parse_common(char *line, char *path, t_scene *mini_rt, char **data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			return (parse_resolution(line + 1 + i, path, "R", mini_rt, data));
		else if (line[i] == 'A')
			return (parse_ambiant_light_data(line + 1 + i, "A", mini_rt, data));
		else if (line[i] == 'c' && line[i + 1] != 'y')
			return (parse_camera_data(line + 1 + i, "c", mini_rt, data));
		else if (line[i] == 'l')
			return (parse_light_data(line + 1 + i, "l", mini_rt, data));
		else
			i++;
	}
	return (-1);
}

int	parse_objects(char *line, t_scene *mini_rt, char **data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 's' && line[i + 1] == 'p')
			return (parse_sphere_data(line + 2 + i, "sp", mini_rt, data));
		else if (line[i] == 's' && line[i + 1] == 'q')
			return (parse_square_data(line + 2 + i, "sq", mini_rt, data));
		else if (line[i] == 't' && line[i + 1] == 'r')
			return (parse_triangle_data(line + 2 + i, "tr", mini_rt, data));
		else if (line[i] == 'c' && line[i + 1] == 'y')
			return (parse_cylinder_data(line + 2 + i, "cy", mini_rt, data));
		else if (line[i] == 'p' && line[i + 1] == 'l')
			return (parse_plan_data(line + 2 + i, "pl", mini_rt, data));
		else
			i++;
	}
	return (-1);
}

int	read_and_parse(char *file_path, t_scene *mini_rt)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		parser_engine(line, file_path, mini_rt);
		free(line);
		line = NULL;
	}
	parser_engine(line, file_path, mini_rt);
	free(line);
	line = NULL;
	return (0);
}
