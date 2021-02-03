/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 15:17:45 by tbillon          ###   ########lyon.fr   */
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

#define PI 3.14159265359;

/* This file contains all others headers and additionals functions */

/* ERRORS FUNCTIONS */
int		error_code(int error_code);
int		params_check(int ac, char **av);

/* CHECK FUNCTIONS */
int		check_format(char *str, char *type);
int		check_R_format(char *str);
int		check_A_format(char *str);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path);
int		parser_engine(char *line, char *file_path);
int		parse_light_data(char *str, char *type);
int		parse_camera_data(char *str, char *type);
int		parse_ambiant_light_data(char *str, char *type);
int		parse_resolution(char *str, char *file_path, char *type);
int		parse_sphere_data(char *str, char *type);
int		parse_square_data(char *str, char *type);
int		parse_plan_data(char *str, char *type);
int		parse_cylinder_data(char *str, char *type);
int		parse_triangle_data(char *str, char *type);

#endif