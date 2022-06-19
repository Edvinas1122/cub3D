#include "utils.h"

/*
	checks if the given point belongs to a wall
	if wall returns 1
*/
int	check_door(t_data *data, t_vect point, int direction)
{
	int	tmp;
	int	x;
	int	y;

	x = point.x / TILE_SIZE;
	y = point.y / TILE_SIZE;
	if (direction == 1)
		tmp = (int)fmod(point.x, TILE_SIZE);
	else
		tmp = (int)fmod(point.y, TILE_SIZE);
	if (tmp < (int)(double)data->map.doormap[y][x].closed_percentage
		* (double)TILE_SIZE / 100)
		return (1);
	else
		return (0);
}

int	check_if_wall(t_data *data, t_vect point)
{
	int	x;
	int	y;

	x = point.x / TILE_SIZE;
	y = point.y / TILE_SIZE;
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

static void	set_around(t_vect *around, t_vect point)
{
	int		barrier;
	t_vect	vect;
	int		i;

	vect.x = 0.5;
	vect.y = 0.5;
	barrier = TILE_SIZE / 3 + 1;
	i = 0;
	while (i < 4)
	{
		rotate_vector(&vect, 90);
		around[i].x = point.x + vect.x * barrier;
		around[i].y = point.y + vect.y * barrier;
		i++;
	}
}

int	check_if_solid_around(t_data *data, t_vect point)
{
	t_vect	*around;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	around = ft_calloc(5, sizeof(t_vect));
	set_around(around, point);
	while (i < 4 && !flag)
	{
		if (check_if_solid(data, around[i]))
			flag = 1;
		i++;
	}
	free(around);
	if (flag == 1)
		return (1);
	return (0);
}
