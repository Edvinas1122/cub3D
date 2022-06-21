/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:12:11 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/21 12:30:51 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	all_rows_begin_check(char **map, char *valid_char)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!compare_to_str2(map[i][0], valid_char))
			return (0);
		i++;
	}
	return (1);
}

static int	check_one_player(char **map, char *valid_char)
{
	int	flag;
	int	i;
	int	i2;

	flag = 0;
	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (compare_to_str2(map[i][i2], valid_char) && !flag)
				flag = 1;
			else if (compare_to_str2(map[i][i2], valid_char) && flag)
				return (0);
			i2++;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

static int	valid_map_characters(char **map, char *valid_char)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (!compare_to_str2(map[i][i2], valid_char))
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

static int	doors_enclosed_check(char **map)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (map[i][i2] == '2')
			{
				if (!(map[i - 1][i2] == '1' && map[i + 1][i2] == '1') && \
					!(map[i][i2 - 1] == '1' && map[i][i2 + 1] == '1'))
					return (0);
			}
			i2++;
		}
		i++;
	}
	return (1);
}

/* 
	Validates map segment of a file for all required criteria 
*/
int	validate_map(char **map)
{
	if (!valid_map_characters(map, "210NWESD "))
	{
		ft_putstr_fd("Invalid map character\n", 1);
		return (0);
	}
	if (!check_one_player(map, "NWESD"))
	{
		ft_putstr_fd("More than one or none players found\n", 1);
		return (0);
	}
	if (!all_rows_begin_check(map, "1 ") || \
		!check_bottom_row(map, "1 ") || \
		!all_rows_closed(map) || \
		!check_leaping_column_uncloses(map, "1") || \
		!matrix_neighbour_check(map, "20NWESD"))
	{
		ft_putstr_fd("Unclosed map\n", 1);
		return (0);
	}
	if (!doors_enclosed_check(map))
	{
		ft_putstr_fd("Invalid door\n", 1);
		return (0);
	}
	return (1);
}
