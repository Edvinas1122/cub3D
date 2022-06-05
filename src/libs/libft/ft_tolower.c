/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:42:31 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/13 16:20:07 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*Convert uppercase letter to lowercase
*/
int	ft_tolower(int c)
{
	if (c > 64 && c <= 90)
		return (c + 32);
	else
		return (1);
}
