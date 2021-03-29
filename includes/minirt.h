/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 13:19:14 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "colors.h"
#include "scenes.h"
#include "utils.h"
#include "vectors.h"
#include "element.h"
#include "resolve.h"
#include "../minilibx/mlx.h"
#include <pthread.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

# define THREAD_COUNT 4

/* This file contains all others headers and additionals functions */

typedef	struct	s_thread
{
	int	start;
	int	end;
	int index;
	t_vectors	P;
	t_vectors	N;
	t_scene		rt;
	pthread_t 	pthr;
	t_ray	  	ray;
}				t_thread;

/* ERRORS FUNCTIONS */
int		error_code(int error_code, char *name);
int		params_check(int ac, char **av);

/* CHECK FUNCTIONS */
int		check_format_engine(char *str, char *type, char **data);
int		check_res_format(char *str, char *type, char **data);
int		check_amb_format(char *type, char **data);
int		check_c_format(char *type, char **data);
int		check_l_format(char *type, char **data);
int		check_sphere_format(char *type, char **data);
int		check_square_format(char *type, char **data);
int		check_plan_format(char *type, char **data);
int		check_cylinder_format(char *type, char **data);
int		check_triangle_format(char *type, char **data);
t_vectors	check_intensity(t_vectors pxl_intensity);
int		check_range_colors(char *code);
int		check_range_vector(char *code);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path, t_scene	*mini_rt);
int		parser_engine(char *line, char *path, t_scene *mini_rt);
int		parse_elements(char *line, t_scene *mini_rt, char **data);
int		parse_common(char *line, char *path, t_scene *mini_rt, char **data);
int		parse_light_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_camera_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_amb_light_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_res(char *str, char *path, t_scene *mini_rt, char **data);
int		parse_sphere_data(char *type, t_scene *mini_rt, char **data);
int		parse_square_data(char *type, t_scene *mini_rt, char **data);
int		parse_plan_data(char *type, t_scene *mini_rt, char **data);
int		parse_cylinder_data(char *type, t_scene *mini_rt, char **data);
int		parse_triangle_data(char *type, t_scene *mini_rt, char **data);

/* MATHS FUNCTIONS */
int	test_sign(double delta, double a, double b);
void get_text(t_ray *ray, t_scene *mini_rt, t_element *sphere, int *col, int *row);

/* RAY */
void	update_ray(t_thread *th, double index_hor, double index_ver);
t_ray	gen_ray(t_scene *rt, double index_hor, double index_ver);

/* MLX RELATIVES */
int	set_img(t_scene *rt);

/* SPHERE RELATIVES */
int	sphere_intersection(t_thread *th);
void put_sphere(t_thread *th, int index);

/* PLAN RELATIVES */
int	plan_intersection(t_thread *th);
void put_plan(t_thread *th, int index);

/* DISPLAY */
void	display_elements(t_thread *th, int index);

/* RAYTRACING */
void	*raytrace(t_thread *th);

/* THREAD */
void	create_thread(t_scene *rt);

#endif