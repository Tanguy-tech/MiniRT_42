/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:41:08 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 13:34:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_strrchr(char *s, int c)
{
	char	*haystack;
	char	car;
	int		i;

	i = 0;
	car = (char)c;
	haystack = (char *)s;
	while (haystack[i])
		i++;
	while (i >= 0)
	{
		if (haystack[i] == car)
			return (haystack + 1 + i);
		i--;
	}
	return (0);
}
