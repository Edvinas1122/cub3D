#include "mechanics.h"

static void	all_keys_relesed(t_data *data)
{
	if (data->keys.key_w[0] == 0 && data->keys.key_w[1] == 0
		&& data->keys.key_s[0] == 0 && data->keys.key_s[1] == 0
		&& data->keys.key_a[0] == 0 && data->keys.key_a[1] == 0
		&& data->keys.key_d[0] == 0 && data->keys.key_d[1] == 0)
	{
		data->player.movement.x = 0;
		data->player.movement.y = 0;
	}
}

void	unset_movement_vector(t_data *data)
{
	if (data->keys.key_w[0] == 0 && data->keys.key_w[1] == 1)
	{
		move_backwards(data);
		data->keys.key_w[1] = 0;
	}
	else if (data->keys.key_s[0] == 0 && data->keys.key_s[1] == 1)
	{
		move_forward(data);
		data->keys.key_s[1] = 0;
	}
	else if (data->keys.key_a[0] == 0 && data->keys.key_a[1] == 1)
	{
		move_right(data);
		data->keys.key_a[1] = 0;
	}
	else if (data->keys.key_d[0] == 0 && data->keys.key_d[1] == 1)
	{
		move_left(data);
		data->keys.key_d[1] = 0;
	}
	all_keys_relesed(data);
}

void	set_movement_vector(t_data *data)
{
	if (data->keys.key_w[0] == 1 && data->keys.key_w[1] == 0)
	{
		move_forward(data);
		data->keys.key_w[1] = 1;
	}
	if (data->keys.key_s[0] == 1 && data->keys.key_s[1] == 0)
	{
		move_backwards(data);
		data->keys.key_s[1] = 1;
	}
	if (data->keys.key_a[0] == 1 && data->keys.key_a[1] == 0)
	{
		move_left(data);
		data->keys.key_a[1] = 1;
	}
	if (data->keys.key_d[0] == 1 && data->keys.key_d[1] == 0)
	{
		move_right(data);
		data->keys.key_d[1] = 1;
	}	
}
