/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:08 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/21 12:38:11 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	find_char_in_row(char *row, char *c)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (compare_to_str2(row[i], c))
			return (i);
		i++;
	}
	return (-1);
}

/*
	Finds character in an array and returns it's
	coordinate representation.
*/
t_vect	find_char_cordinates(char **map, char *c)
{
	int		y;
	int		x;
	t_vect	pos;

	y = 0;
	while (map[y])
	{
		x = find_char_in_row(map[y], c);
		if (x != -1)
		{
			pos.x = x;
			pos.y = y;
			return (pos);
		}
		y++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

static char	*find_char_in_row_add(char *row, char *c)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (compare_to_str2(row[i], c))
			return (&row[i]);
		i++;
	}
	return (NULL);
}

/*
	Finds character in an array and returns it's
	address.
*/
char	*find_char(char **map, char *c)
{
	int		i;
	char	*address;

	i = 0;
	while (map[i])
	{
		address = find_char_in_row_add(map[i], c);
		if (address)
			return (address);
		i++;
	}
	return (NULL);
}
