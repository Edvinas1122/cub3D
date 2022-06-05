/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:43:45 by emomkus           #+#    #+#             */
/*   Updated: 2021/06/01 16:47:21 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*searches for mach in string
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*ptr;

	ptr = (char *) big;
	i = 0;
	j = 0;
	size = ft_strlen(little);
	if (size == 0)
		return (ptr);
	if (len < size)
		return (0);
	while (i < len - size + 1 && ptr[i] != 0)
	{
		j = 0;
		while (j < size && ptr[i + j] == little[j])
		{
			j++;
			if (j == size)
				return (&ptr[i]);
		}
		i++;
	}
	return (0);
}
