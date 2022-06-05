#include "validation.h"

static void	check_around(char **map, int i, int i2)
{
	if (compare_to_str2(map[i + 1][i2 - 1], " \0"))
		exit(0);
	else if (compare_to_str2(map[i + 1][i2], " \0"))
		exit(0);
	else if (compare_to_str2(map[i + 1][i2 + 1], " \0"))
		exit(0);
	else if (compare_to_str2(map[i][i2 - 1], " \0"))
		exit(0);
	else if (compare_to_str2(map[i][i2 + 1], " \0"))
		exit(0);
	else if (compare_to_str2(map[i - 1][i2 - 1], " \0"))
		exit(0);
	else if (compare_to_str2(map[i - 1][i2], " \0"))
		exit(0);
	else if (compare_to_str2(map[i - 1][i2 + 1], " \0"))
		exit(0);
	
}

/*
	Itterates trough matrix and checks victims member's neibgrours
	if victim has \0 or " " (space) as a member - invalid
	map format
*/
void	matrix_neighbour_check(char **map, char *victims)
{
	int	i;
	int	i2;
	int	*lenghts;

	lenghts = line_lenghts(map);
	i = 1;
	while (map[i + 1])
	{
		i2 = 1;
		while (lenghts[i] > i2)
		{
			if (compare_to_str2(map[i][i2], victims))
				check_around(map, i, i2);
			i2++;
		}
		i++;
	}
	free(lenghts);
}
