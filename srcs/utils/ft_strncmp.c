/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:40:30 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 16:37:42 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	i = 0;
	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (n > 0)
	{
		while (s1_[i] && s2_[i] && i < n - 1)
		{
			if (s1_[i] != s2_[i])
				return (s1_[i] - s2_[i]);
			i++;
		}
	}
	return (s1_[i] - s2_[i]);
}
