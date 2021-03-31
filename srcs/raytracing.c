/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:26:44 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/30 12:47:47 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	create_thread(t_scene *rt)
{
	t_thread	thread[THREAD_COUNT];
	int i;
	double size;

	i = 0;
	size = rt->res.x / THREAD_COUNT;
	while (i < THREAD_COUNT)
	{
		thread[i].rt = *rt;
		thread[i].start = i * size;
		thread[i].end = (i + 1) * size;
		thread[i].ray = gen_ray(rt, thread[i].start, 0);
		thread[i].index = 2 + (i * size * 4);
		pthread_create(&thread[i].pthr, NULL, (void*)raytrace, &thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread[i].pthr, NULL);
		i++;
	}
}

void	*raytrace(t_thread *th)
{
	int i;
	int j;
	int index_tab;
	
	j = 0;
	while (j < th->rt.res.y)
	{
		i = th->start;
		index_tab = j * (th->rt.res.x * 4) + th->index;
		while (i < th->end)
		{
			update_ray(th, i, j);
			display_elements(th, index_tab);
			i++;
			index_tab += 4;
		}
		j++;
	}
	pthread_exit(th->pthr);
	return (0);
}
	