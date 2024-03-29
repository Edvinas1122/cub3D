/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:58 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:05:59 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	delete_list_node(void *lst)
{
	t_list	*node;

	node = lst;
	free(node->content);
	free(node);
}

void	lst_clear_2(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	node = *list;
	while (node)
	{
		tmp = node->next;
		free(node->content);
		free(node);
		node = tmp;
	}
	free(list);
}
