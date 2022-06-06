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
	cordinate representation.
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
		}
			return (pos);
		y++;
	}
	return();
}

static char	*find_char_in_row(char *row, char *c)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (compare_to_str2(row[i], c))
			return (row[i]);
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
	char	address;

	i = 0;
	while (map[i])
	{
		address = find_char_in_row(map[i], c);
		if (address)
			return(address);
		i++;
	}
	return(NULL);
}
