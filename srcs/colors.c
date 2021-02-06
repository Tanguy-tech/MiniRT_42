/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:22:47 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:40:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colors.h"
#include "../includes/utils.h"

t_colors	*initialize_colors(void)
{
	t_colors	*new_color;

	if (!(new_color = ft_calloc(sizeof(t_colors), 1)))
		return (NULL);
	new_color->r = 0.0;
	new_color->g = 0.0;
	new_color->b = 0.0;
	return (new_color);
}
