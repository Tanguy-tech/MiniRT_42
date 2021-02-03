/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:46:36 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 12:18:26 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_calloc(int count, int size)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = malloc(count * size)))
		return (0);
	while (i < (size * count))
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
