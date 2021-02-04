/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 10:26:05 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scenes.h"
#include "../includes/utils.h"
#include "../includes/colors.h"

s_ambiant_light	*initialize_ambiant_light(void)
{
	s_ambiant_light	*new_ambiant_light;

	if (!(new_ambiant_light = ft_calloc(sizeof(s_ambiant_light), 1)))
		return (NULL);
		new_ambiant_light->ratio = 0.0;
		new_ambiant_light->color = initialize_colors();
		return (new_ambiant_light);
}