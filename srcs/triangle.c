/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:14 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 14:14:04 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/utils.h"

t_triangle	*initialize_triangle(void)
{
	t_triangle	*new_triangle;

	if (!(new_triangle = ft_calloc(sizeof(t_triangle), 1)))
		return (NULL);
	new_triangle->firts_coord = initialize_vector();
	new_triangle->sec_coord = initialize_vector();
	new_triangle->third_coord = initialize_vector();
	new_triangle->color = initialize_colors();
	return (new_triangle);
}