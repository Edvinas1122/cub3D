#include "validation.h"

static void	all_rows_begin_check(char **map, char *valid_char)
{
	int	i;

	i = 0;
	while (map[i])
	{
		compare_to_str(map[i][0], valid_char);
		i++;
	}
}

// static void check_required_chars(map, "10NWESD")
// {

// }

static void	valid_map_characters(char **map, char *valid_char)
{
	int	i;
	int i2;

	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			//printf("test\n");
			compare_to_str(map[i][i2], valid_char);
			i2++;
		}
		i++;
	}
}

/* 
	Validates map segment of a file for all required criteria 
*/
void	validate_map(char **map)
{
	valid_map_characters(map, "10NWESD ");
	printf("Map contains valid chars\n");
	//valid_prop_count(map, "");
	all_rows_begin_check(map, "1 ");
	// check_required_chars(map, "10NWESD");
	matrix_neighbour_check(map, "0NWESD");
}
