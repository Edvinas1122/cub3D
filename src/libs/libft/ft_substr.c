/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:11:22 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/30 01:38:41 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*Returns a new string from string- starting on offset (start) and lenght of len
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*str;
	unsigned int	strl;

	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	else
		strl = ft_strlen(s) - start;
	if (len < strl)
		str = (char *)malloc(sizeof(const char) * (len + 1));
	else
		str = (char *)malloc(sizeof(const char) * (strl + 1));
	i = 0 + start;
	j = 0;
	while (s[i] && len--)
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}
