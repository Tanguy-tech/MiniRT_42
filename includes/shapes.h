/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:41:37 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 15:27:34 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
#define SHAPES_H

#include "colors.h"
#include "vectors.h"

typedef struct	sphere
{
	double		x;			/* Coordinate on x axis */
	double		y;			/* Coordinate on y axis */
	double		z;			/* Coordinate on z axis */
	double		diam;		/* Sphere diameter */
	s_colors	color;		/* Sphere color */
}				s_sphere;

typedef struct	square
{
	double		x;				/* Coordinate on x axis */
	double		y;				/* Coordinate on y axis */
	double		z;				/* Coordinate on z axis */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		height;			/* Height of square side */
	s_colors	color;			/* Square color */
}				s_square;

typedef struct	plan
{
	double		x;				/* Coordinate on x axis */
	double		y;				/* Coordinate on y axis */
	double		z;				/* Coordinate on z axis */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	s_colors	color;			/* Plan color */
}				s_plan;

typedef struct	cylinder
{
	double		x;				/* Coordinate on x axis */
	double		y;				/* Coordinate on y axis */
	double		z;				/* Coordinate on z axis */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		diam;			/* Cylinder diameter */
	double		height;			/* Cylinder height */
	s_colors	color;			/* Cylinder color */
}				s_cylinder;

typedef struct	triangle
{
	double		A_x;		/* Coordinate of point A on x axis */
	double		A_y;		/* Coordinate of point A on y axis */
	double		A_z;		/* Coordinate of point A on z axis */

	double		B_x;		/* Coordinate of point B on x axis */
	double		B_y;		/* Coordinate of point B on y axis */
	double		B_z;		/* Coordinate of point B on z axis */

	double		C_x;		/* Coordinate of point C on x axis */
	double		C_y;		/* Coordinate of point C on y axis */
	double		C_z;		/* Coordinate of point C on z axis */
	s_colors	color;		/* Triangle color */

}				s_triangle;

#endif
