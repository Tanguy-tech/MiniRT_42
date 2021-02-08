/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:16:19 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/08 11:20:30 by tbillon          ###   ########lyon.fr   */
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
		new_cam->x = 0.0;
		new_cam->y = 0.0;
		new_cam->z = 0.0;
		new_cam->orientation = initialize_vector();
		new_cam->fov = 0.0;
		return (new_cam);
}

t_light		*initialize_light(void)
{
	t_light	*new_light;

	if (!(new_light = ft_calloc(sizeof(t_light), 1)))
		return (NULL);
	new_light->x = 0.0;
	new_light->y = 0.0;
	new_light->z = 0.0;
	new_light->light_ratio = 0.0;
	new_light->color = initialize_colors();
	return (new_light);
}

t_scene		*initialize_scene(void)
{
	t_scene	*new_scene;

	if (!(new_scene = ft_calloc(sizeof(t_scene), 1)))
		return (NULL);
		new_scene->mlx_ptr = mlx_init();
		new_scene->amb_light = initialize_ambiant_light();
		new_scene->cam = initialize_camera();
		new_scene->light = initialize_light();
		new_scene->window = initialize_window();
		new_scene->sp = initialize_sphere();
		new_scene->pl = initialize_plan();
		return (new_scene);
}