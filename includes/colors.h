/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:07:10 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/06 10:37:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

/* This file contains the color structures and all functions relatives to colors contstruction */

typedef struct colors
{
	double	r;	/* precise number of red color [0-255]*/
	double	g;	/* precise number of green color [0-255]*/
	double	b;	/* precise number of blue color [0-255]*/
}				t_colors;

t_colors	*initialize_colors(void);

#endif