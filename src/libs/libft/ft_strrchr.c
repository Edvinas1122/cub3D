/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:54:36 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/24 00:45:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			temp = i + 1;
		}
		i++;
	}
	if (temp)
	{
		temp--;
		return ((char *)&s[temp]);
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}
