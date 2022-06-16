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

void	move_right(t_data *data)
{
	t_vect	tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, 90);
	data->player.movement.x = tmp.x;
	data->player.movement.y = tmp.y;
}

void	move_left(t_data *data)
{
	t_vect	tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, -90);
	data->player.movement.x = tmp.x;
	data->player.movement.y = tmp.y;
}
