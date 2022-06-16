#include "control.h"

void	move_forward(t_data *data)
{
	data->player.movement.x = data->player.vect.x;
	data->player.movement.y = data->player.vect.y;
}


void	move_backwards(t_data *data)
{	
	data->player.movement.x = (data->player.vect.x) * -1;
	data->player.movement.y = (data->player.vect.y) * -1;
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
	if (!check_if_wall(destination, data->map.bit_map))
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
	if (!check_if_wall(destination, data->map.bit_map))
	{
		data->player.pos.x = destination.x;
		data->player.pos.y = destination.y;
	}
}
