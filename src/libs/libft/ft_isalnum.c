/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:29:25 by emomkus           #+#    #+#             */
/*   Updated: 2021/05/24 15:33:47 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*Checks whether c is either a decimal digit or an uppercase or lowercase letter
*/
int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c <= 122) || (c > 47 && c < 58))
		return (1);
	return (0);
}
