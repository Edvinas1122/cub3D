/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:25:10 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/29 23:15:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*returns value of bytes in strings, appends to destination src of size
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	start;
	size_t	j;

	start = 0;
	j = 0;
	while (dest[start] != '\0' && start < size)
		start++;
	while (src[j] != '\0' && j + start + 1 < size)
	{
		dest[start + j] = src[j];
		j++;
	}
	if (size != 0 && size > start)
		dest[start + j] = '\0';
	return (start + ft_strlen(src));
}
