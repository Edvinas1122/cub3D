#include "utils.h"

/*
	checks if the given point belongs to a wall
*/
int	check_if_wall(t_vect *point, char **bitmap)
{
	int x = point->x / 100;
	int y = point->y / 100;

	if (bitmap[y][x] == '1')
		return (1);
	else
		return (0);
}
