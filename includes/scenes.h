/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 10:25:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
#define SCENES_H

#include "colors.h"
#include "vectors.h"
#include "shapes.h"

/* This file contains the objects structure and all functions relatives to the objects construction */

typedef struct	ambiant_light
{
	double		ratio;	/* ration of ambiant light in [0.0/1.0] range */
	s_colors	*color;	/* Color of ambiant light */
}				s_ambiant_light;

s_ambiant_light	*initialize_ambiant_light(void);

typedef struct	camera
{
	double		x;				/* Camera position on x axis */
	double		y;				/* Camera position on y axis */
	double		z;				/* Camera position on z axis */
	s_vectors	orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		fov;			/* Field of view - angle in degrees in [0.0/180.0] range */
}				s_camera;

typedef struct	light
{
	double		x;				/* Light position on x axis */
	double		y;				/* Light position on y axis */
	double		z;				/* Light position on z axis */
	double		light_ratio;	/* Ratio of light in [0.0/1.0] range */
	s_colors	color;			/* Light color */
}				s_light;

typedef struct	scene
{
	s_ambiant_light	amb_light;	/* Ambiant light structure */
	s_camera		cam;		/* Camera position structure */
	s_light			light;		/* Light structure */
	s_sphere		sp;			/* Sphere structure object */
	s_square		sq;			/* Square structure object */
	s_plan			pl;			/* Plan structure object */
	s_cylinder		cy;			/* Cylinder structure object */
	s_triangle		tr;			/* Triangle structure object */
}				s_scene;

#endif