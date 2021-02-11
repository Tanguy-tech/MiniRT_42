/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:44:09 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 11:46:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
#define IMG_H

#include "scenes.h"

typedef	struct	img
{
	t_scene	*scene;
	int		x;
	int		bit_per_pixel;
	int		size_line;
	char	*data;
}				t_img;

t_img	*initialize_img(void);

#endif