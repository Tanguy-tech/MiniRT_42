/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:41:37 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 09:46:40 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
#define SHAPES_H

#include "colors.h"
#include "vectors.h"

typedef struct	sphere
{
	s_vectors	origin_coord;	/* Sphere ogirin coordinates in space */
	double		diam;			/* Sphere diameter */
	s_colors	color;			/* Sphere color */
}				s_sphere;

typedef struct	square
{
	s_vectors	coord;			/* Square coordinates in space */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		height;			/* Height of square side */
	s_colors	color;			/* Square color */
}				s_square;

typedef struct	plan
{
	s_vectors	coord;			/* Coordinates of the plan in space */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	s_colors	color;			/* Plan color */
}				s_plan;

typedef struct	cylinder
{
	s_vectors	origin_coord;	/* Cylinder ogirin coordinates in space */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		diam;			/* Cylinder diameter */
	double		height;			/* Cylinder height */
	s_colors	color;			/* Cylinder color */
}				s_cylinder;

typedef struct	triangle
{
	s_vectors	firts_coord;	/* Triangle first point coordinates in space */
	s_vectors	sec_coord;		/* Triangle sec point coordinates in space */
	s_vectors	third_coord;	/* Triangle third point coordinates in space */
	s_colors	color;			/* Triangle color */

}				s_triangle;

#endif
