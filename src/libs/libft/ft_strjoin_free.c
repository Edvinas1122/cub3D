/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:12 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/28 17:16:25 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len1;
	int		total_len;
	char	*output;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1) + 1;
	total_len = len1 + ft_strlen(s2);
	output = malloc(total_len);
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, (char *)s1, len1);
	ft_strlcat(output, (char *)s2, total_len);
	free(s2);
	free(s1);
	return (output);
}
