/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 09:39:05 by tbillon          ###   ########lyon.fr   */
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
# define RES_FORMAT "Wrong format in .rt file! Check again R format (RESOLUTION)."
# define AMB_FORMAT "Wrong format in .rt file! Check again A format (AMBIANT)."
# define CAM_FORMAT "Wrong format in .rt file! Check again c format (CAM)."
# define LIGHT_FORMAT "Wrong format in .rt file! Check again l format (LIGHT)."
# define EXEC_FORMAT "First arg must be ./miniRT, second must be .rt file."
# define MISS_FILE "Wrong number of arguments, missing scene file (type *.rt)."
# define PLAN_FORMAT "Wrong format in .rt file! Check again pl format (PLAN)."
# define SPHERE_FORMAT "Wrong format in .rt file! Check again sp format (SPHERE)."
# define SQUARE_FORMAT "Wrong format in .rt file! Check again sq format (SQUARE)."
# define CYL_FORMAT "Wrong format in .rt file! Check again cy format (CYLINDER)."
# define TRI_FORMAT "Wrong format in .rt file! Check again tr format (TRIANGLE)."
# define MLX_ERR "A problem occured when trying to create mlx img."

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
int		handle_error(char *msg, int code);

/* CHECK FUNCTIONS */
int		check_format_engine(char *str, char *type, char **data);
int		check_res_format(char *str, char **data);
int		check_amb_format(char **data);
int		check_c_format(char **data);
int		check_l_format(char **data);
int		check_sphere_format(char **data);
int		check_square_format(char **data);
int		check_plan_format(char **data);
int		check_cylinder_format(char **data);
int		check_triangle_format(char **data);
t_vectors	check_intensity(t_vectors pxl_intensity);
int		check_range_color(char *code);
int		check_range_vector(char *code);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path, t_scene	*mini_rt);
int		parser_engine(char *line, char *path, t_scene *mini_rt);
int		parse_elements(char *line, t_scene *mini_rt, char **data);
int		parse_common(char *line, char *path, t_scene *mini_rt, char **data);
int		parse_light_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_camera_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_amblight_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_res(char *str, char *path, t_scene *mini_rt, char **data);
int		parse_sphere_data(t_scene *mini_rt, char **data);
int		parse_square_data(t_scene *mini_rt, char **data);
int		parse_plan_data(t_scene *mini_rt, char **data);
int		parse_cylinder_data(t_scene *mini_rt, char **data);
int		parse_triangle_data(t_scene *mini_rt, char **data);

/* MATHS FUNCTIONS */
int	test_sign(double delta, double a, double b);

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

/* SQUARE RELATIVES */
int	square_intersection(t_thread *th);
void	put_square(t_thread *th, int index);

/* CYLINDER RELATIVES */
int	cylinder_intersection(t_thread *th);
void	put_cylinder(t_thread *th, int index);

/* TRIANGLE RELATIVES */
void	put_triangle(t_thread *th, int index);
int	triangle_intersection(t_thread *th);

/* DISPLAY */
void	display_elements(t_thread *th, int index);

/* RAYTRACING */
void	*raytrace(t_thread *th);

/* THREAD */
void	create_thread(t_scene *rt);

#endif