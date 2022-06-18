#include "../../cube3d.h"

/*
	Controls colision
*/
static void	collisios_slide(t_data *data)
{
	t_vect	destination;

	destination.x = data->player.pos.x + data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y;
	if (!check_if_solid_around(data, destination))
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
	else
	{
		destination.x = data->player.pos.x;
		destination.y = data->player.pos.y + data->player.movement.y * data->util.move_factor;
		if (!check_if_solid_around(data, destination))
		{
			data->player.pos.x = destination.x;	
			data->player.pos.y = destination.y;	
		}
	}
}

static void	dash(t_data *data)
{
	if (data->keys.key_space[0] == 1 && data->keys.key_space[1] == 0)
	{
		data->keys.key_space[1] = 1;
		data->player.dash_cooldown = 18;
	}
	if (data->player.dash_cooldown > 13)
		data->util.move_factor *= 3.5;
	if (data->player.dash_cooldown)
		data->player.dash_cooldown--;
	if (data->util.move_factor > TILE_SIZE - 10)
		data->util.move_factor = 80;
}

void	player_movement(t_data *data)
{
	t_vect	destination;

	dash(data);
	set_movement_vector(data);
	unset_movement_vector(data);
	destination.x = data->player.pos.x + data->player.movement.x * data->util.move_factor;
	destination.y = data->player.pos.y + data->player.movement.y * data->util.move_factor;
	if (check_if_solid_around(data, destination))
		collisios_slide(data);
	else
	{
		data->player.pos.x = destination.x;	
		data->player.pos.y = destination.y;	
	}
}