/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:41:37 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 08:05:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
#define ELEMENT_H

#include "colors.h"
#include "vectors.h"

typedef	struct	s_element
{
	t_colors	*color;			/* Color of the current element */
	t_vectors	*orig;			/* Origin coordinates of the current element */
	t_vectors	*dir;			/* Direction normalised vector of the current element */
	t_vectors	*first_coord;	/* coordinate in 3d space if applicable */
	t_vectors	*sec_coord;		/* coordinate in 3d space if applicable */
	t_vectors	*third_coord;	/* coordinate in 3d space if applicable */
	double		height;			/* Height of the current element if applicable */
	double		diam;			/* Diameter of current element if applicable */
	double		ray;			/* Ray of current element if applicable  */
	int			id;			/* ID of the current element 1-sphere 2-plane 3-square 4-cylinder 5-triangle */
}				t_element;

t_element	*initialize_element(void);

#endif
