/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/08 09:59:28 by tbillon          ###   ########lyon.fr   */
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

t_camera	*initialize_camera(void)
{
	t_camera	*new_cam;

	if (!(new_cam = ft_calloc(sizeof(t_camera), 1)))
		return (NULL);
	new_cam->coord = initialize_vector();
	new_cam->direction = initialize_vector();
	new_cam->fov = 0.0;
	return (new_cam);
}

t_light	*initialize_light(void)
{
	t_light	*new_light;

	if (!(new_light = ft_calloc(sizeof(t_light), 1)))
		return (NULL);
	new_light->coord = initialize_vector();
	new_light->light_ratio = 0.0;
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
	new_element->P = initialize_vector();
	new_element->N = initialize_vector();
	new_element->first_coord = initialize_vector();
	new_element->sec_coord = initialize_vector();
	new_element->third_coord = initialize_vector();
	new_element->height = 0.0;
	new_element->diam = 0.0;
	new_element->ray = 0.0;
	new_element->id = 0;
	return (new_element);
}

t_scene	*initialize_scene(void)
{
	t_scene	*new_scene;

	if (!(new_scene = ft_calloc(sizeof(t_scene), 1)))
		return (NULL);
	new_scene->mlx_ptr = mlx_init();
	new_scene->amb_light = initialize_ambiant_light();
	new_scene->cam = initialize_camera();
	new_scene->light = initialize_light();
	new_scene->window = initialize_window();
	// new_scene->sp = initialize_sphere();
	// new_scene->pl = initialize_plan();
	// new_scene->sq = initialize_square();
	// new_scene->cy = initialize_cylinder();
	// new_scene->tr = initialize_triangle();
	// new_scene->element = initialize_element();
	return (new_scene);
}
