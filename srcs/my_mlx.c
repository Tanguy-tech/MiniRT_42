/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:22:02 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 11:25:49 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_mlx.h"
#include "../includes/utils.h"

t_mlx	*initialize_my_mlx(void)
{
	t_mlx	*new_my_mlx;

	if (!(new_my_mlx = ft_calloc(sizeof(t_mlx), 1)))
		return (NULL);
	new_my_mlx->bit_per_pixel = 0;
	new_my_mlx->size_line = 0;
	new_my_mlx->endian = 0;
	new_my_mlx->data = "\0";
	return (new_my_mlx);
}
