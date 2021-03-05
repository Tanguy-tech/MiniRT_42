/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:41:37 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/05 15:15:57 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
#define SHAPES_H

#include "colors.h"
#include "vectors.h"

typedef struct	sphere
{
	t_vectors	*origin_coord;	/* Sphere ogirin coordinates in space */
	double		diam;			/* Sphere diameter */
	double		ray;			/* Ray of the sphere */
	t_colors	*color;			/* Sphere color */
	int			count;
	t_vectors	*P;
	t_vectors	*N;
	double		t;
}				t_sphere;

t_sphere	*initialize_sphere(void);

typedef struct	square
{
	t_vectors	*coord;			/* Square coordinates in space */
	t_vectors	*orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		height;			/* Height of square side */
	t_colors	*color;			/* Square color */
	int			count;
}				t_square;

t_square	*initialize_square(void);

typedef struct	plan
{
	t_vectors	*coord;			/* Coordinates of the plan in space */
	t_vectors	*orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	t_colors	*color;			/* Plan color */
	int			count;
	double		t;
}				t_plan;

t_plan	*initialize_plan(void);

typedef struct	cylinder
{
	t_vectors	*origin_coord;	/* Cylinder ogirin coordinates in space */
	t_vectors	*orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		diam;			/* Cylinder diameter */
	double		height;			/* Cylinder height */
	t_colors	*color;			/* Cylinder color */
	int			count;
}				t_cylinder;

t_cylinder	*initialize_cylinder(void);

typedef struct	triangle
{
	t_vectors	*first_coord;	/* Triangle first point coordinates in space */
	t_vectors	*sec_coord;		/* Triangle sec point coordinates in space */
	t_vectors	*third_coord;	/* Triangle third point coordinates in space */
	t_colors	*color;			/* Triangle color */
	int			count;

}				t_triangle;

t_triangle	*initialize_triangle(void);

#endif
