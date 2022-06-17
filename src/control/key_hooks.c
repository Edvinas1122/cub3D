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
	if (keycode == 49)
		data->keys.key_space[0] = 1;
	if (keycode == 123)
		return (&rotate_player_left);
	if (keycode == 124)
		return (&rotate_player_right);
	if (keycode == 48)
		return (&pop_minimap);
	if (keycode == 53)
		return (&menu_pop);
	return (NULL);
}

int	player_action(int keycode, t_data *data)
{
	void (*action)(t_data *);

	action = get_action_function(keycode, data);
	if (action)
		action(data);
	return (0);
}

// subtract from movement acording to dir
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
		data->keys.key_space[0] = 0;
	return (0);
}

int	red_x_win(t_data *data)
{
	close_win(data);
	return (0);
}

int	player_mouse_action(int x, int y, t_data *data)
{
	(void) data;
	y++;
	if (x > 1)
		rotate_player(data, x);
	else if (x < -1)
		rotate_player(data, x);
	mlx_mouse_move(data->mlx.win, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}

int	player_mouse_action_stop(int x, int y, t_data *data)
{
	(void) data;
	x++;
	y++;
	return (0);
}

