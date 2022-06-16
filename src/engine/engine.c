#include "../cube3d.h"

static void	move_single_axis(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x + data->player.movement.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y;
	if (!check_if_wall(destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
	else
	{
		destination.x = data->player.pos.x;
		destination.y = data->player.pos.y + data->player.movement.y * MOVE_DISTANCE;
		if (!check_if_wall(destination, data->map.bit_map))
		{
			data->player.pos.x = destination.x;	
			data->player.pos.y = destination.y;	
		}
	}
}

static void	player_movement(t_data *data)
{
	t_vect			destination;

	destination.x = data->player.pos.x + data->player.movement.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y + data->player.movement.y * MOVE_DISTANCE;
	if (check_if_wall(destination, data->map.bit_map))
		move_single_axis(data);
	else
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
}

int	engine(t_data *data)
{
	// struct timeval	time;
	// long			difference;

	// gettimeofday(&time, NULL);
	// data->util.time_stamp = time.tv_usec;
	player_movement(data);
	render_display(data);
	// gettimeofday(&time, NULL);
	// difference = time.tv_usec - data->util.time_stamp;
	// if (difference > 0)
	// 	data->util.frame_rate = 1000000 / (difference);
	return (0);
}
