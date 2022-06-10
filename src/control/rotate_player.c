#include "control.h"

void	rotate_player_left(t_data *data)
{
	rotate_vector(&data->player.vect, -5);
}

void	rotate_player_right(t_data *data)
{
	rotate_vector(&data->player.vect, 5);
}