/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:55:53 by tbillon           #+#    #+#             */
/*   Updated: 2021/04/02 11:22:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*list;

	i = 0;
	list = lst;
	if (!lst)
		return (0);
	while (list->next != NULL)
	{
		i++;
		list = list->next;
	}
	return (list);
}

int	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (alst)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return (1);
		}
		else
		{
			list = ft_lstlast(*(alst));
			list->next = new;
			return (1);
		}
	}
	return (0);
}
