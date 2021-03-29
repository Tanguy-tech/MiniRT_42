/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/29 08:52:46 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scenes.h"
#include "../includes/utils.h"

t_ambiant_light	*initialize_ambiant_light(void)
{
	t_ambiant_light	*new_ambiant_light;

	if (!(new_ambiant_light = ft_calloc(sizeof(t_ambiant_light), 1)))
		return (NULL);
	new_ambiant_light->ratio = 0.0;
	new_ambiant_light->color = initialize_colors();
	return (new_ambiant_light);
}

t_light	*initialize_light(void)
{
	t_light	*new_light;

	if (!(new_light = ft_calloc(sizeof(t_light), 1)))
		return (NULL);
	new_light->orig = initialize_vector();
	new_light->ratio = 0.0;
	new_light->color = initialize_colors();
	new_light->P = initialize_vector();
	new_light->N = initialize_vector();
	return (new_light);
}

t_element	*initialize_element(void)
{
	t_element	*new_element;

	if (!(new_element = ft_calloc(sizeof(t_element), 1)))
		return (NULL);
	new_element->color = initialize_colors();
	new_element->orig = initialize_vector();
	new_element->dir = initialize_vector();
	new_element->first_coord = initialize_vector();
	new_element->sec_coord = initialize_vector();
	new_element->third_coord = initialize_vector();
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
	new_scene->amb_light = initialize_ambiant_light();
	new_scene->light = initialize_light();
	new_scene->img = initialize_image();
	new_scene->count_elem = 0;
	new_scene->thread_id = 0;
	return (new_scene);
}
