#include "control.h"

void	rotate_player_left(t_data *data)
{
	rotate_vector(&data->player.vect, -3);
}

void	rotate_player_right(t_data *data)
{
	rotate_vector(&data->player.vect, 3);
}

void	rotate_player(t_data *data, int x)
{
	double	strenght;

	strenght = x;
	strenght /= MOUSE_SENSITIVITY;
	//data->player.rotate = strenght;
	rotate_vector(&data->player.vect, strenght);
}