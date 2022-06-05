/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:22:06 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/27 20:20:39 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pt;
	int		ct;

	pt = lst;
	ct = 1;
	if (lst == NULL)
		return (0);
	while (pt->next != NULL)
	{
		pt = pt->next;
		ct++;
	}
	return (ct);
}
