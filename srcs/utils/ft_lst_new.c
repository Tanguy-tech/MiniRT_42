/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:03:12 by tbillon           #+#    #+#             */
/*   Updated: 2021/03/08 09:03:22 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	if (!(new_content = malloc(sizeof(t_list))))
		return (0);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
