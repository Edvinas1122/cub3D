#include "utils.h"

/*
	checks if the given point belongs to a wall
	if wall returns 1
*/
int	check_if_wall(t_vect point, char **bitmap)
{
	int x = point.x / TILE_SIZE;
	int y = point.y / TILE_SIZE;

	if (bitmap[y][x] == '1')
		return (1);
	else
		return (0);
}
