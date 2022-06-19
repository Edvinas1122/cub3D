#include "validation.h"

int	all_rows_closed(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom_row(char **map, char *valid_char)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (map[i][i2])
	{
		if (!compare_to_str2(map[i][i2], valid_char))
			return (0);
		i2++;
	}
	i2 = 0;
	while (map[i + 1])
		i++;
	while (map[i][i2])
	{
		if (!compare_to_str2(map[i][i2], valid_char))
			return (0);
		i2++;
	}
	return (1);
}

int	free_and_get_out(int *lengths)
{
	free(lengths);
	return (0);
}

/*
	Checks for leaping 0 over row below
*/
int	check_leaping_column_uncloses(char **map, char *valid_char)
{
	int	i;
	int	i2;
	int	column;
	int	*lengths;

	lengths = line_lengths(map);
	column = 0;
	i = 1;
	while (map[i + 1])
	{
		i2 = 0;
		while (lengths[i] - i2)
		{
			if (!compare_to_str2(map[i][lengths[i] - i2 - 1], valid_char))
				break ;
			column = lengths[i] - i2;
			i2++;
		}
		i2 = 0;
		if (column > lengths[i + 1] || column > lengths[i - 1])
			return (free_and_get_out(lengths));
		i++;
	}
	free(lengths);
	return (1);
}
