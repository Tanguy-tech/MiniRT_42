/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:49:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 10:50:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		get_next_line(int fd, char **line)
{
	static char *st[4096];
	char		buff[1];
	char		*tmp;
	int			pos;

	if (!(line) || (!(st[fd]) && !(st[fd] = ft_calloc(1, sizeof(char)))))
		return (-1);
	while (read(fd, buff, 1) > 0)
	{
		st[fd] = str_add_char(st[fd], buff[0]);
		if (buff[0] == '\n')
			break;
	}
	if ((pos = to_find(st[fd], '\n')) >= 0)
	{
		*line = ft_substr(st[fd], 0, pos);
		tmp = st[fd];
		st[fd] = ft_substr(st[fd], pos + 1, to_find(st[fd], '\n'));
		free(tmp);
		return (1);
	}
	*line = ft_substr(st[fd], 0, to_find(st[fd], '\0'));
	free(st[fd]);
	return (0);
}
