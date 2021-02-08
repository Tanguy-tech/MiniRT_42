/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:32:18 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 13:20:47 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	find_next_code(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (i);
		i++;
	}
	return (0);
}

char	*trunc_code(char *str, int index)
{
	char	*code;
	
	if (!(code = ft_calloc(sizeof(char), 4)))
		return (NULL);
	while (str[index] != ',' && str[index])
	{
		if (!(code = str_add_char(code, str[index])))
			return (NULL);
		index++;
	}
	return (code);
}