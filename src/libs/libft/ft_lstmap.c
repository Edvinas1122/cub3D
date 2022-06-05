/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 05:50:38 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/27 20:19:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelement;
	t_list	*result;

	result = ft_lstnew((*f)(lst->content));
	if (result == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst -> next;
		newelement = ft_lstnew((*f)(lst->content));
		if (newelement == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, newelement);
	}
	return (result);
}
