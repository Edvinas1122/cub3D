#include "control.h"

static void	*get_action_function(int keycode, t_data *data)
{
	if (keycode == 0)
		data->keys.key_a[0] = 1;
	if (keycode == 2)
		data->keys.key_d[0] = 1;
	if (keycode == 1 || keycode == 125)
		data->keys.key_s[0] = 1;
	if (keycode == 13 || keycode == 126)
		data->keys.key_w[0] = 1;
	if (keycode == 14)
		return (&toggle_door);
	if (keycode == 49)
		data->keys.key_space[0] = 1;
	if (keycode == 123)
		return (&rotate_player_left);
	if (keycode == 124)
		return (&rotate_player_right);
	if (keycode == 48)
		return (&pop_minimap);
	if (keycode == 34)
		return (&menu_pop);
	if (keycode == 53)
		return (&close_win);
	return (NULL);
}

int	player_action(int keycode, t_data *data)
{
	void	(*action)(t_data *);

	action = get_action_function(keycode, data);
	if (action)
		action(data);
	if (keycode == 35)
		printf("\nPlayer position x: %f\nPlayer position y: %f\n", data->player.pos.x, data->player.pos.y);
	return (0);
}

/*
	Subtract from movement acording to dir
*/
int	player_stop_movement(int keycode, t_data *data)
{
	if (keycode == 0)
		data->keys.key_a[0] = 0;
	if (keycode == 2)
		data->keys.key_d[0] = 0;
	if (keycode == 1 || keycode == 125)
		data->keys.key_s[0] = 0;
	if (keycode == 13 || keycode == 126)
		data->keys.key_w[0] = 0;
	if (keycode == 49)
	{
		data->keys.key_space[1] = 0;
		data->keys.key_space[0] = 0;
	}
	return (0);
}

int	player_mouse_action(int x, int y, t_data *data)
{
	long	mouse_x;
	long	mouse_y;

	mouse_x = SCREEN_WIDTH / 2;
	mouse_y = SCREEN_HEIGHT / 2;
	y++;
	rotate_player(data, x - mouse_x);
	mlx_mouse_move(data->mlx.win, (void *)mouse_x, mouse_y, 0);
	return (0);
}

int	player_mouse_action_stop(int x, int y, t_data *data)
{
	(void) data;
	x++;
	y++;
	return (0);
}
