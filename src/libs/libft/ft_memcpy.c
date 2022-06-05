/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:52:25 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/28 23:38:43 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*coppies to destination n amount contents of source
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*stmp;
	char		*dtmp;

	dtmp = dest;
	stmp = src;
	while (n)
	{
		*dtmp = *stmp;
		dtmp++;
		stmp++;
		n--;
	}
	return (dest);
}
