#include "utils.h"

/*
	checks if the given point belongs to a wall
	if wall returns 1
*/
int	check_door(t_data *data, t_door door, t_vect point, int direction)
{
	int	tmp;

	if (direction == 1)
	{
		tmp = (int)fmod(point.x, TILE_SIZE);
		if (data->player.pos.y > point.y)
			tmp = TILE_SIZE - tmp;
	}
	else
	{
		tmp = (int)fmod(point.y, TILE_SIZE);
		if (data->player.pos.x > point.x)
			tmp = TILE_SIZE - tmp;
	}
	if (tmp < door.closed_percentage)
		return (1);
	else
		return (0);
}

int	check_if_wall(t_data *data, t_vect point, int direction)
{
	int x = point.x / TILE_SIZE;
	int y = point.y / TILE_SIZE;

	if (data->map.bit_map[y][x] == '1')
		return (1);
	else if (data->map.bit_map[y][x] == '2')
	{
		if (check_door(data, data->map.doormap[y][x], point, direction))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
