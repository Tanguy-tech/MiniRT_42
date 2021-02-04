/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 14:46:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scenes.h"
#include "../includes/utils.h"

s_ambiant_light	*initialize_ambiant_light(void)
{
	s_ambiant_light	*new_ambiant_light;

	if (!(new_ambiant_light = ft_calloc(sizeof(s_ambiant_light), 1)))
		return (NULL);
		new_ambiant_light->ratio = 0.0;
		new_ambiant_light->color = initialize_colors();
		return (new_ambiant_light);
}

s_camera	*initialize_camera(void)
{
	s_camera	*new_cam;

	if (!(new_cam = ft_calloc(sizeof(s_camera), 1)))
		return (NULL);
		new_cam->x = 0.0;
		new_cam->y = 0.0;
		new_cam->z = 0.0;
		new_cam->orientation = initialize_vector();
		new_cam->fov = 0.0;
		return (new_cam);
}

s_light		*initialize_light(void)
{
	s_light	*new_light;

	if (!(new_light = ft_calloc(sizeof(s_light), 1)))
		return (NULL);
	new_light->x = 0.0;
	new_light->y = 0.0;
	new_light->z = 0.0;
	new_light->light_ratio = 0.0;
	new_light->color = initialize_colors();
}

s_scene		*initialize_scene(void)
{
	s_scene	*new_scene;

	if (!(new_scene = ft_calloc(sizeof(s_scene), 1)))
		return (NULL);
		new_scene->mlx_ptr = mlx_init();
		new_scene->amb_light = initialize_ambiant_light();
		new_scene->cam = initialize_camera();
		new_scene->light = initialize_light();
		new_scene->window = initialize_window();
		return (new_scene);
}