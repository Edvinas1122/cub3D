/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:35:56 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/19 21:44:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*nexttoptr;

	if (lst == NULL)
		return ;
	nexttoptr = *lst;
	while (nexttoptr->next != NULL)
	{
		ptr = nexttoptr;
		nexttoptr = nexttoptr ->next;
		ft_lstdelone(ptr, del);
	}
	ft_lstdelone(nexttoptr, del);
	*lst = NULL;
}
