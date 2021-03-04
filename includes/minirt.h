/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/04 13:17:57 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "colors.h"
#include "scenes.h"
#include "utils.h"
#include "vectors.h"
#include "window.h"
#include "shapes.h"
#include "ray.h"
#include "../minilibx/mlx.h"

#define PI 3.14159265359;

/* This file contains all others headers and additionals functions */

/* ERRORS FUNCTIONS */
int		error_code(int error_code, char *name);
int		params_check(int ac, char **av);

/* CHECK FUNCTIONS */
int		check_format_engine(char *str, char *type, char **data);
int		check_res_format(char *str, char *type, char **data);
int		check_amb_format(char *str, char *type, char **data);
int		check_c_format(char *str, char *type, char **data);
int		check_l_format(char *str, char *type, char **data);
int		check_sphere_format(char *str, char *type, char **data);
int		check_square_format(char *str, char *type, char **data);
int		check_plan_format(char *str, char *type, char **data);
int		check_cylinder_format(char *str, char *type, char **data);
int		check_triangle_format(char *str, char *type, char **data);
double	check_intensity(double pxl_intensity);
int		check_range_colors(char *code);
int		check_range_vector(char *code);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path, t_scene	*mini_rt);
int		parser_engine(char *line, char *path, t_scene *mini_rt);
int		parse_objects(char *line, t_scene *mini_rt, char **data);
int		parse_common(char *line, char *path, t_scene *mini_rt, char **data);
int		parse_light_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_camera_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_amb_light_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_res(char *str, char *path, t_scene *mini_rt, char **data);
int		parse_sphere_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_square_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_plan_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_cylinder_data(char *str, char *type, t_scene *mini_rt, char **data);
int		parse_triangle_data(char *str, char *type, t_scene *mini_rt, char **data);

/* MATHS FUNCTIONS */
int	sphere_intersection(t_ray *ray, t_sphere *sphere, t_vectors *P, t_vectors *N);
int	test_sign(double delta, double a, double b);

/* MLX RELATIVES */
int	set_img(t_scene	*mini_rt);

/* SPHERE RELATIVES */
void	put_sphere(t_scene *mini_rt, t_vectors *pxl_intensity, t_ray *ray, int index);

#endif