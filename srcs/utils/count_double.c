/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:51:59 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 08:19:45 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	count_double(char *str)
{
	int i;
	int	dbl;

	i = 0;
	dbl = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1]) && str[i] == '.')
			dbl++;
		i++;
	}
	return (dbl);
}
