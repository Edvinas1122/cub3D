#include "../../cube3d.h"

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

void	player_movement(t_data *data)
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