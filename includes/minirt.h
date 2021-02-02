/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:33:00 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/02 14:42:19 by tbillon          ###   ########lyon.fr   */
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

/* This file contains all others headers and additionals functions */
int		error_code(int error_code);
int		errors_check(int ac, char **av);
int		read_and_parse(char *file_path);

#endif