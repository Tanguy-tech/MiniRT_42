/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:41:37 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:39:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
#define SHAPES_H

#include "colors.h"
#include "vectors.h"

typedef struct	sphere
{
	t_vectors	origin_coord;	/* Sphere ogirin coordinates in space */
	double		diam;			/* Sphere diameter */
	t_colors	color;			/* Sphere color */
}				t_sphere;

typedef struct	square
{
	t_vectors	coord;			/* Square coordinates in space */
	t_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		height;			/* Height of square side */
	t_colors	color;			/* Square color */
}				t_square;

typedef struct	plan
{
	t_vectors	coord;			/* Coordinates of the plan in space */
	t_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	t_colors	color;			/* Plan color */
}				t_plan;

typedef struct	cylinder
{
	t_vectors	origin_coord;	/* Cylinder ogirin coordinates in space */
	t_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		diam;			/* Cylinder diameter */
	double		height;			/* Cylinder height */
	t_colors	color;			/* Cylinder color */
}				t_cylinder;

typedef struct	triangle
{
	t_vectors	firts_coord;	/* Triangle first point coordinates in space */
	t_vectors	sec_coord;		/* Triangle sec point coordinates in space */
	t_vectors	third_coord;	/* Triangle third point coordinates in space */
	t_colors	color;			/* Triangle color */

}				t_triangle;

#endif
