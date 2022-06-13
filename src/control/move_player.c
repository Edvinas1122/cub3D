#include "control.h"

static void	move_single_axis(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x + data->player.vect.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y;
	if (!check_if_wall(&destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
	else
	{
		destination.x = data->player.pos.x;
		destination.y = data->player.pos.y + data->player.vect.y * MOVE_DISTANCE;
		if (!check_if_wall(&destination, data->map.bit_map))
		{
			data->player.pos.x = destination.x;	
			data->player.pos.y = destination.y;	
		}
	}
}

void	move_forward(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x + data->player.vect.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y + data->player.vect.y * MOVE_DISTANCE;
	if (check_if_wall(&destination, data->map.bit_map))
		move_single_axis(data);
	else
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
	// data->player.pos.x += data->player.vect.x * MOVE_DISTANCE;
	// data->player.pos.y += data->player.vect.y * MOVE_DISTANCE;
}

void	move_backwards(t_data *data)
{	
	t_vect	destination;

	destination.x = data->player.pos.x - data->player.vect.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y - data->player.vect.y * MOVE_DISTANCE;
	if (!check_if_wall(&destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
}

void	move_left(t_data *data)
{
	t_vect	tmp;
	t_vect	destination;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, 90);
	destination.x = data->player.pos.x - tmp.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y - tmp.y * MOVE_DISTANCE;
	if (!check_if_wall(&destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
}

void	move_right(t_data *data)
{
	t_vect	tmp;
	t_vect	destination;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, -90);
	destination.x = data->player.pos.x  - tmp.x * MOVE_DISTANCE;
	destination.y = data->player.pos.y - tmp.y * MOVE_DISTANCE;
	if (!check_if_wall(&destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
}
