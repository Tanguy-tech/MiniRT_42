/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:41:47 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 11:43:23 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		size_num(int x)
{
	size_t i;

	i = 0;
	if (x == 0)
		return (1);
	if (!x)
		return (0);
	while (x != 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}
