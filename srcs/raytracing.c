/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:26:44 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/17 17:17:51 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	create_thread(t_scene *rt)
{
	t_thread	thread[THREAD_COUNT];
	int i;
	t_ray	*ray;

	i = 0;
	while (i < THREAD_COUNT)
	{
		thread[i].current = i;
		thread[i].size = rt->res->x / THREAD_COUNT;
		thread[i].rt = rt;
		thread[i].start = i * thread[i].size;
		thread[i].end = (i + 1) * thread[i].size;
		ray = gen_ray(rt, thread[i].start, 0);
		thread[i].ray = ray;
		thread[i].index = 2 + (i * thread[i].size);
		pthread_create(&thread[i].pthr, NULL, raytrace, &thread);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(thread[i].pthr, NULL);
		i++;
	}
}

void	*raytrace(void *mini_rt)
{
	double i;
	double j;
	int k;
	t_thread *th;
	
	th = (t_thread*)mini_rt;
	j = 0;
	while (j < th->rt->res->y)
	{
		i = th->start;
		while (i < th->end)
		{
			update_ray(th->ray, th->rt, i/th->rt->res->x, j/th->rt->res->x);
			display_elements(th->rt, th->ray, th->index, j);
			i++;
			th->index += 4;
		}
		j++;
	}
	pthread_exit(th->pthr);
	return (0);
}
