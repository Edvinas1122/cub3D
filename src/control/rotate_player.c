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
	rotate_vector(&data->player.vect, strenght);
	rotate_vector(&data->player.movement, strenght);
}

int	red_x_win(t_data *data)
{
	close_win(data);
	return (0);
}
