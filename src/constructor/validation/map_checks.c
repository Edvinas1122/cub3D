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

/*
	Checks for leaping 0 over row below
*/
int	check_leaping_column_uncloses(char **map, char *valid_char)
{
	int	i;
	int	i2;
	int	column;
	int	*lenghts;

	lenghts = line_lenghts(map);
	column = 0;
	i = 1;
	while (map[i + 1])
	{
		i2 = 0;
		while (lenghts[i] - i2)
		{
			if (!compare_to_str2(map[i][lenghts[i] - i2 - 1], valid_char))
				break ;
			column = lenghts[i] - i2;
			i2++;
		}
		i2 = 0;
		if (column > lenghts[i + 1] || column > lenghts[i - 1])
		{
			free(lenghts);
			return (0);
		}
		i++;
	}
	free(lenghts);
	return (1);
}
