/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:09:32 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:11:49 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/utils.h"

t_cylinder	*initialize_cylinder(void)
{
	t_cylinder	*new_cylinder;

	if (!(new_cylinder = ft_calloc(sizeof(t_cylinder), 1)))
		return (NULL);
	new_cylinder->origin_coord = initialize_vector();
	new_cylinder->orientation = initialize_vector();
	new_cylinder->diam = 0.0;
	new_cylinder->height = 0.0;
	new_cylinder->color = initialize_colors();
	return (new_cylinder);
}