/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:57:56 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/06 07:30:31 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
