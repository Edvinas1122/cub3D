#include "../../cube3d.h"

static void	move_single_axis(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x + data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y;
	if (!check_if_wall(destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
	else
	{
		destination.x = data->player.pos.x;
		destination.y = data->player.pos.y + data->player.movement.y * data->util.move_factor;
		if (!check_if_wall(destination, data->map.bit_map))
		{
			data->player.pos.x = destination.x;	
			data->player.pos.y = destination.y;	
		}
	}
}

static void	dash(t_data *data)
{
	if (data->player.dash > 0 && data->player.dash < 6)
	{
		data->util.move_factor *= 3.5;
		data->player.dash++;
		if (data->player.dash == 5)
		{
			data->player.dash_cooldown = 9;
			data->player.dash = 0;
		}
	}
	if (data->player.dash_cooldown)
		data->player.dash_cooldown--;
	if (data->util.move_factor > TILE_SIZE)
		data->util.move_factor = 80;
}

void	player_movement(t_data *data)
{
	t_vect			destination;

	// rotate_vector(&data->player.vect, data->player.rotate * data->util.move_factor/MOVE_DISTANCE);
	// data->player.rotate = 0;
	dash(data);
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