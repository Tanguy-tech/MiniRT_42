/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:41:02 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 10:16:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	check_neg(int fac, char c)
{
	if (c == '-')
		fac = -1;
	return (fac);
}

int	check_fac(int fac, int i)
{
	if (fac == -1)
		i++;
	return (i);
}

float	ft_atof(char *str)
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;

	fac = 1;
	atof = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	fac = check_neg(fac, str[i]);
	atoi = ft_atoi(str);
	i += size_num(atoi);
	i = check_fac(fac, i);
	if (str[i] != '.')
		return (atoi);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fac *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	atof = atof / fac;
	return (atoi + atof);
}
