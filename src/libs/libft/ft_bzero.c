/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:48:34 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/22 21:03:23 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*write n of zeros in destionation
*/
void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n != 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
