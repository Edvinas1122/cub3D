/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:15:16 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/30 03:01:01 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*sets string contents to char c until n
*/
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n != 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}
