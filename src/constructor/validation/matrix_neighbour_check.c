/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_neighbour_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:12:06 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:12:07 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	check_around(char **map, int i, int i2)
{
	if (compare_to_str2(map[i + 1][i2 - 1], " \0"))
		return (0);
	else if (compare_to_str2(map[i + 1][i2], " \0"))
		return (0);
	else if (compare_to_str2(map[i + 1][i2 + 1], " \0"))
		return (0);
	else if (compare_to_str2(map[i][i2 - 1], " \0"))
		return (0);
	else if (compare_to_str2(map[i][i2 + 1], " \0"))
		return (0);
	else if (compare_to_str2(map[i - 1][i2 - 1], " \0"))
		return (0);
	else if (compare_to_str2(map[i - 1][i2], " \0"))
		return (0);
	else if (compare_to_str2(map[i - 1][i2 + 1], " \0"))
		return (0);
	return (1);
}

/*
	Itterates trough matrix and checks victims member's neibgrours
	if victim has \0 or " " (space) as a member - invalid
	map format
*/
int	matrix_neighbour_check(char **map, char *victims)
{
	int	i;
	int	i2;
	int	*lenghts;

	lenghts = line_lengths(map);
	i = 1;
	while (map[i + 1])
	{
		i2 = 1;
		while (lenghts[i] > i2)
		{
			if (compare_to_str2(map[i][i2], victims))
			{
				if (!check_around(map, i, i2))
				{
					free(lenghts);
					return (0);
				}
			}
			i2++;
		}
		i++;
	}
	free(lenghts);
	return (1);
}
