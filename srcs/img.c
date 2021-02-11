/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:46:47 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/11 11:48:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/img.h"
#include "../includes/utils.h"

t_img	*initialize_img(void)
{
	t_img	*new_img;

	if (!(new_img = ft_calloc(sizeof(t_img), 1)))
		return (NULL);
	new_img->x = 0;
	new_img->bit_per_pixel = 0;
	new_img->size_line = 0;
	return (new_img);
}
