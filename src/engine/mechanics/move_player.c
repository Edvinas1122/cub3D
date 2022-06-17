#include "../../cube3d.h"

// movement start begin problem because 
void	move_forward(t_data *data)
{
	data->player.movement.x += data->player.vect.x;
	data->player.movement.y += data->player.vect.y;
	//normalize_vector_t(&data->player.movement);
}


void	move_backwards(t_data *data)
{	
	data->player.movement.x -= data->player.vect.x;
	data->player.movement.y -= data->player.vect.y;
	//normalize_vector_t(&data->player.movement);
}

void	move_right(t_data *data)
{
	t_vect	tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, 90);
	data->player.movement.x += tmp.x;
	data->player.movement.y += tmp.y;
	//normalize_vector_t(&data->player.movement);
}

void	move_left(t_data *data)
{
	t_vect	tmp;

	tmp.x = data->player.vect.x;
	tmp.y = data->player.vect.y;
	rotate_vector(&tmp, -90);
	data->player.movement.x += tmp.x;
	data->player.movement.y += tmp.y;
	//normalize_vector_t(&data->player.movement);
}
