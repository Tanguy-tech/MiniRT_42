/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:15:03 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 11:21:52 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MY_MLX_H
#define MY_MLX_H

#include "scenes.h"

typedef	struct	my_mlx
{
	void		*img_ptr;
	void		*win_ptr;
	void		*img;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	char		*data;
	t_scene		*scene;
}				t_mlx;

t_mlx	*initialize_my_mlx(void);

#endif