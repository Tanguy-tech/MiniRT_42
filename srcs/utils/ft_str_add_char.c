/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:47:46 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:05:54 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*str_add_char(char *str, char c)
{
	int		i;
	char	*new;
	int		len;

	len = ft_strlen(str);
	i = 0;
	new = ft_calloc(len + 2, sizeof(char));
	if (!(new))
		return (0);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	if (str)
		free(str);
	return (new);
}
