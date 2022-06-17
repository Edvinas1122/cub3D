#include "utils.h"

/*
	checks if the given point belongs to a wall
	if wall returns 1
*/
int	check_door(t_data *data, t_vect point, int direction)
{
	int	tmp;
	int x = point.x / TILE_SIZE;
	int y = point.y / TILE_SIZE;

	// printf("%d %d is checked\n", x, y);
	if (direction == 1)
		tmp = (int)fmod(point.x, TILE_SIZE);
	else
		tmp = (int)fmod(point.y, TILE_SIZE);
	if (tmp < (int)(double)data->map.doormap[y][x].closed_percentage * (double)TILE_SIZE/100)
		return (1);
	else
		return (0);
}

int	check_if_wall(t_data *data, t_vect point)
{
	int x = point.x / TILE_SIZE;
	int y = point.y / TILE_SIZE;

	if (data->map.bit_map[y][x] == '1')
		return (1);
	else if (data->map.bit_map[y][x] == '2')
		return (2);
	else
		return (0);
}

int	check_if_solid(t_data *data, t_vect point)
{
	int	x;
	int	y;
	int	walltype;

	walltype = check_if_wall(data, point);
	if (walltype == 1)
		return (1);
	x = point.x / TILE_SIZE;
	y = point.y / TILE_SIZE;
	if (walltype == 2)
		if (data->map.doormap[y][x].solid == 1)
			return (1);
	return (0);
}