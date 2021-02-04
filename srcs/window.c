/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:58:49 by tbillon           #+#    #+#             */
/*   Updated: 2021/02/04 12:57:29 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/window.h"
#include "../includes/utils.h"

s_window	*initialize_window(void)
{
	s_window	*new_window;

	if (!(new_window = ft_calloc(sizeof(s_window), 1)))
		return (NULL);
	new_window->res_x = 0;
	new_window->res_y = 0;
	new_window->title = "\0";
	return (new_window);
}
