/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:14:01 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/09 14:20:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/resolve.h"

t_resolve	*initialize_resolve(void)
{
	t_resolve	*solve;

	if (!(solve = ft_calloc(sizeof(t_resolve), 1)))
		return (NULL);
	solve->a = 0.0;
	solve->b = 0.0;
	solve->c = 0.0;
	solve->delta = 0.0;
	solve->t1 = 0.0;
	solve->t2 = 0.0;
	solve->sub = initialize_vector();
	return (solve);
}
