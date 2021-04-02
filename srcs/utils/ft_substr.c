/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:48:34 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:06:08 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_substr(char *str, int begin, int len_max)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_calloc(len_max + 1, sizeof(char));
	if (!(new))
		return (0);
	while (str[begin] && i < len_max)
	{
		new[i] = str[begin];
		i++;
		begin++;
	}
	return (new);
}
