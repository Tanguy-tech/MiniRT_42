/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:54:03 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
#define SCENES_H

#include "colors.h"
#include "vectors.h"
#include "shapes.h"
#include "window.h"
#include "../minilibx/mlx.h"

/* This file contains the objects structure and all functions relatives to the objects construction */

typedef struct	ambiant_light
{
	double		ratio;	/* ration of ambiant light in [0.0/1.0] range */
	t_colors	*color;	/* Color of ambiant light */
}				t_ambiant_light;

t_ambiant_light	*initialize_ambiant_light(void);

typedef struct	camera
{
	double		x;				/* Camera position on x axis */
	double		y;				/* Camera position on y axis */
	double		z;				/* Camera position on z axis */
	t_vectors	*orientation;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		fov;			/* Field of view - angle in degrees in [0.0/180.0] range */
}				t_camera;

t_camera		*initialize_camera(void);

typedef struct	light
{
	double		x;				/* Light position on x axis */
	double		y;				/* Light position on y axis */
	double		z;				/* Light position on z axis */
	double		light_ratio;	/* Ratio of light in [0.0/1.0] range */
	t_colors	*color;			/* Light color */
}				t_light;

t_light			*initalize_light(void);

typedef struct	scene
{
	void			*mlx_ptr;		/* pointer to location of current mlx instance */
	t_window		*window;		/* Window structure */
	t_ambiant_light	*amb_light;		/* Ambiant light structure */
	t_camera		*cam;			/* Camera position structure */
	t_light			*light;			/* Light structure */
	t_sphere		*sp;			/* Sphere structure object */
	t_square		*sq;			/* Square structure object */
	t_plan			*pl;			/* Plan structure object */
	t_cylinder		*cy;			/* Cylinder structure object */
	t_triangle		*tr;			/* Triangle structure object */
}				t_scene;

t_scene			*initialize_scene(void);

#endif