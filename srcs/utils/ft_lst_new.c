/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:03:12 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 14:03:08 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = malloc(sizeof(t_list));
	if (!(new_content))
		return (0);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
