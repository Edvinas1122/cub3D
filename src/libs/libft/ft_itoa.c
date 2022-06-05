/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:32:40 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/28 16:09:38 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*malloc char string from integer
*/
static int	negativet(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	lenght(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nit;
	char			*str;
	char			num;
	int				len;
	int				index;

	index = negativet(n);
	len = lenght(n);
	str = malloc((len + 1 + index) * sizeof(char));
	str[len + index] = 0;
	if (index)
		nit = (unsigned int)n * -1;
	else
		nit = (unsigned int)n;
	while ((len + index) > (0 + index))
	{
		len--;
		num = (nit % 10) + 48;
		nit = nit / 10;
		str[len + index] = num;
	}
	if (index)
		str[0] = '-';
	return (str);
}
