/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 13:00:12 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scenes.h"
#include "../includes/utils.h"

t_element	*initialize_element(void)
{
	t_element	*new_element;

	if (!(new_element = ft_calloc(sizeof(t_element), 1)))
		return (NULL);
	new_element->height = 0.0;
	new_element->diam = 0.0;
	new_element->ray = 0.0;
	new_element->id = 0;
	return (new_element);
}

t_image	*initialize_image(void)
{
	t_image	*new_img;

	if (!(new_img = ft_calloc(sizeof(t_image), 1)))
		return (NULL);
	return (new_img);
}

t_scene	*initialize_scene(void)
{
	t_scene	*new_scene;

	if (!(new_scene = ft_calloc(sizeof(t_scene), 1)))
		return (NULL);
	new_scene->mlx_ptr = mlx_init();
	new_scene->img = initialize_image();
	return (new_scene);
}
