/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:16 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 10:58:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
#define SCENES_H

#include "colors.h"
#include "vectors.h"
#include "element.h"
#include "res.h"
#include "image.h"
#include "../minilibx/mlx.h"

/* This file contains the objects structure and all functions relatives to the objects construction */

typedef struct		s_list
{
	t_element		*content;
	struct s_list	*next;
}					t_list;

typedef struct	ambiant_light
{
	double		ratio;	/* ration of ambiant light in [0.0/1.0] range */
	t_colors	color;	/* Color of ambiant light */
}				t_ambiant_light;

t_ambiant_light	*initialize_ambiant_light(void);

typedef struct	camera
{
	t_vectors	orig;
	t_vectors	dir;	/* Vector of 3d orientation in [-1.0/1.0] range for each x,y and z axises */
	double		fov;			/* Field of view - angle in degrees in [0.0/180.0] range */
}				t_camera;

t_camera		*initialize_camera(void);

typedef struct	light
{
	t_vectors	orig;
	double		ratio;	/* Ratio of light in [0.0/1.0] range */
	t_colors	color;			/* Light color */
	t_vectors	*P;
	t_vectors	*N;
}				t_light;

t_light			*initialize_light(void);

typedef	struct ray
{
	t_vectors	orig;	/* Origin point of the ray (vector point) */
	t_vectors	dir;	/* Direction of the ray (vector) */
	t_vectors	norm;
}				t_ray;

t_ray	*initialize_ray(void);

typedef struct	scene
{
	void			*mlx_ptr;		/* pointer to location of current mlx instance */
	void			*win_ptr;
	t_res			res;			/* Resolution of the image/window */
	char			*title;			/* Title of the window */
	t_image			*img;			/* Image structure */
	t_ambiant_light	amb_light;		/* Ambiant light structure */
	t_camera		cam;			/* Camera position structure */
	t_light			light;			/* Light structure */
	t_list			*light_list;
	t_element		element;
	t_list			*elem_list;
	int				count_elem;
	double			t;
	double			k;
	int				thread_id;
}				t_scene;

t_scene			*initialize_scene(void);

#endif