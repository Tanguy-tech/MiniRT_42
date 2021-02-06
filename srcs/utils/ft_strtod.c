/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:46:50 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 11:40:54 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

double	ft_strtod(char *str)
{
	double	a;
	double	b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	a = (double)ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	j = 1;
	while (ft_isdigit(str[i]))
	{
		j++;
		i++;
	}
	b = (1 / pow(10, j)) * (double)ft_atoi(str + j + 1);
	return (a + b);
}
