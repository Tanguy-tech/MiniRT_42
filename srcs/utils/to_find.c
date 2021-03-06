/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:57:56 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 12:57:58 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	to_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
