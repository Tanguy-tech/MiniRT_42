/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 13:51:22 by tbillon          ###   ########lyon.fr   */
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
	new_cam->orig = initialize_vector();
	new_cam->dir = initialize_vector();
	new_cam->up = initialize_vector();
	new_cam->right = initialize_vector();
	new_cam->fov = 0.0;
	return (new_cam);
}

t_light	*initialize_light(void)
{
	t_light	*new_light;

	if (!(new_light = ft_calloc(sizeof(t_light), 1)))
		return (NULL);
	new_light->orig = initialize_vector();
	new_light->light_ratio = 0.0;
	new_light->color = initialize_colors();
	new_light->P = initialize_vector();
	new_light->N = initialize_vector();
	return (new_light);
}

t_texture	*initialize_texture(void)
{
	t_texture	*new_text;

	if (!(new_text = ft_calloc(sizeof(t_texture), 1)))
		return (NULL);
	new_text->height = 0.0;
	new_text->width = 0.0;
	return (new_text);
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
	new_element->tex = initialize_texture();
	new_element->height = 0.0;
	new_element->diam = 0.0;
	new_element->ray = 0.0;
	new_element->id = 0;
	return (new_element);
}

t_res	*initialize_res(void)
{
	t_res	*new_res;

	if (!(new_res = ft_calloc(sizeof(t_res), 1)))
		return (NULL);
	new_res->x = 0;
	new_res->y = 0;
	return (new_res);
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
	new_scene->res = initialize_res();
	new_scene->amb_light = initialize_ambiant_light();
	new_scene->cam = initialize_camera();
	new_scene->light = initialize_light();
	new_scene->img = initialize_image();
	new_scene->ray = initialize_ray();
	new_scene->count_elem = 0;
	return (new_scene);
}
