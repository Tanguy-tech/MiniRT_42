/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:12:54 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 08:13:07 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*dest;

	i = 0;
	from = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (n == 0 || dest == from)
		return (dest);
	while (i < n)
	{
		dest[i] = from[i];
		i++;
	}
	return (dest);
}
