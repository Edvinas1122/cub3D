/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:26 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/21 12:39:33 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* 
	Compares string to a character
	if does not match return 0
	if matches returns 1
*/
int	compare_to_str2(char c, char *valid_char)
{
	int	i;
	int	matching;

	i = 0;
	matching = 0;
	while (valid_char[i])
	{
		if (c == valid_char[i])
			matching = 1;
		i++;
	}
	return (matching);
}
