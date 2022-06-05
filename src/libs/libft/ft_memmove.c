/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:39:22 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/30 02:59:50 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*coppies to destination n amount contents of source
*it does not allow to rewrite what is coppied 
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*stmp;
	char		*dtmp;

	stmp = (char *)src;
	dtmp = (char *)dest;
	if (dtmp < stmp)
	{
		i = 0;
		while (i < n)
		{
			dtmp[i] = stmp[i];
			i++;
		}
	}
	else if (dtmp > stmp)
	{
		i = n;
		while (i > 0)
		{
			dtmp[i - 1] = stmp[i - 1];
			i--;
		}
	}
	return (dest);
}
