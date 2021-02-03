/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/03 09:39:17 by tbillon          ###   ########lyon.fr   */
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
int		check_format(char *str);


/* PARSER FUNCTIONS */
int		read_and_parse(char *file_path);
int		parser_engine(char *line);
int		parse_light_data(char *str);
int		parse_camera_data(char *str);
int		parse_ambiant_light_data(char *str);
int		parse_resolution(char *str);

#endif