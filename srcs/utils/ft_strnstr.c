/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:34:44 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/01 14:08:19 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && i + j < len)
		{
			if (needle[++j] == '\0')
				return (hay + i);
		}
		i++;
	}
	return (hay);
}
