/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:13:41 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 12:46:22 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	is_punctuation(char c)
{
	if (c == ',' || c == '.' || c == '-')
		return (1);
	return (0);
}

int	valid_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_punctuation(str[i]))
			return (0);
		i++;
	}
	return (1);
}
