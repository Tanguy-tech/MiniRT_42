/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/09 10:42:33 by tbillon          ###   ########lyon.fr   */
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
int		check_res_format(char *str, char *type);
int		check_amb_format(char *str, char *type, char **data);
int		check_c_format(char *str, char *type, char **data);
int		check_l_format(char *str, char *type, char **data);
int		check_sphere_format(char *str, char *type, char **data);
int		check_square_format(char *str, char *type, char **data);
int		check_plan_format(char *str, char *type, char **data);
int		check_cylinder_format(char *str, char *type, char **data);
int		check_triangle_format(char *str, char *type, char **data);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path, t_scene	*mini_rt);
int		parser_engine(char *line, char *file_path, t_scene *mini_rt);
int		parse_objects(char *line, char *file_path, t_scene *mini_rt, char **data);
int		parse_common(char *line, char *file_path, t_scene *mini_rt, char **data);
int		parse_light_data(char *str, char *type, t_scene *mini_rt);
int		parse_camera_data(char *str, char *type, t_scene *mini_rt);
int		parse_ambiant_light_data(char *str, char *type, t_scene *mini_rt);
int		parse_resolution(char *str, char *file_path, char *type, t_scene *mini_rt);
int		parse_sphere_data(char *str, char *type, t_scene *mini_rt);
int		parse_square_data(char *str, char *type, t_scene *mini_rt);
int		parse_plan_data(char *str, char *type, t_scene *mini_rt);
int		parse_cylinder_data(char *str, char *type, t_scene *mini_rt);
int		parse_triangle_data(char *str, char *type, t_scene *mini_rt);

#endif