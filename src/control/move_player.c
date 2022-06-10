#include "control.h"

void	move_forward(t_data *data)
{
	data->player.pos.x += data->player.vect.x * MOVE_DISTANCE;
	data->player.pos.y += data->player.vect.y * MOVE_DISTANCE;
}

void	move_backwards(t_data *data)
{
	data->player.pos.x -= data->player.vect.x * MOVE_DISTANCE;
	data->player.pos.y -= data->player.vect.y * MOVE_DISTANCE;
}

void	move_left(t_data *data)
{
	t_vect tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, 90);
	data->player.pos.x -= tmp.x * MOVE_DISTANCE;
	data->player.pos.y -= tmp.y * MOVE_DISTANCE;
}

void	move_right(t_data *data)
{
	t_vect tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, -90);
	data->player.pos.x  -= tmp.x * MOVE_DISTANCE;
	data->player.pos.y -= tmp.y * MOVE_DISTANCE;
}
