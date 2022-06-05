/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:54:32 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/25 20:36:06 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*Compare characters of two strings
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	comp;
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (int)n && s1[i] && s2[i])
	{
		comp = s1[i] - s2[i];
		if (comp != 0)
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	if (i == (int)n)
		return (0);
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
