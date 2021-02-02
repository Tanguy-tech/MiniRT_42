/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:00:26 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 15:42:35 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/* PARSE RESOLUTION */

/* PARSE AMBIANT LIGHT */

/* PARSE CAMERA POSTION */

/* PARSE LIGHT INFORMATIONS */

/* PARSER ENGINE */

int		read_and_parse(char *file_path)
{
	int		fd;
	char	*line;
	
	fd = open(file_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0) /* Function that open and read the file */
	{
		/* Function that parse and save the information in right structures*/
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
		line = NULL;
	}
	/* Function that parse and save the information in right structures*/
	ft_putstr(line);
	free(line);
	line = NULL;
	return (0);
}
