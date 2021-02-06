/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:02:57 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:06:33 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/utils.h"

t_square	*initialize_square(void)
{
	t_square	*new_square;

	if (!(new_square = ft_calloc(sizeof(t_square), 1)))
		return (NULL);
	new_square->coord = initialize_vector();
	new_square->orientation = initialize_vector();
	new_square->height = 0.0;
	new_square->color = initialize_colors();
	return (new_square);
}