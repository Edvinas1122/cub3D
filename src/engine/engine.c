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

	destination.x = data->player.pos.x + data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y + data->player.movement.y * data->util.move_factor;
	if (check_if_wall(destination, data->map.bit_map))
		move_single_axis(data);
	else
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
}

static void	set_time_stamp(t_data *data)
{
	double			time_diff;
	double			move_factor;

	data->util.old_time_stamp = data->util.time_stamp;
	data->util.time_stamp = set_time();
	time_diff = data->util.time_stamp - data->util.old_time_stamp;
	if (time_diff <= 0)
		return ;
	move_factor = (double)(MOVE_DISTANCE) * ((time_diff /33333.0 ));
	printf("\nOne frame time: %f\n", time_diff);
	printf("\nFPS: %f\n", 1000000 / time_diff);
	printf("\nMove factor: %f\n", move_factor);

	// move_factor /= 4000;
	data->util.move_factor = move_factor;
}

int	engine(t_data *data)
{
	set_time_stamp(data);
	player_movement(data);
	render_display(data);
	return (0);
}
