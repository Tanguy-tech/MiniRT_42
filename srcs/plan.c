/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:08:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/utils.h"

t_plan	*initialize_plan(void)
{
	t_plan	*new_plan;

	if (!(new_plan = ft_calloc(sizeof(t_plan), 1)))
		return (NULL);
	new_plan->coord = initialize_vector();
	new_plan->orientation = initialize_vector();
	new_plan->color = initialize_colors();
	return (new_plan);
}