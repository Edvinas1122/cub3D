#include "control.h"

// int	khook(int key, void *param)
// {
// 	// t_mlx	mlx;

// 	// mlx = (t_mlx *) param;
// 	(void) param;
// 	if (key == 65307)
// 	{
// 		// mlx_destroy_image(mlx->ptr, x->img_ptr);
// 		// mlx_destroy_window(x->mlx_ptr, x->win_ptr);
// 		// mlx_loop_end(x->mlx_ptr);
// 		// free(x->img_matrix[x->img_size - 1]);
// 		// free(x->img_matrix);
// 		// free(x->mlx_ptr);
// 		// free(x);
// 		exit(1);
// 	}
// 	return (0);
// }

// int	mhook(int button, int x, int y, void *param)
// {
//     button++;
//     x++;
//     y++;
	
//     (void) param;
// 	return (0);
// }

static void	*get_action_function(int keycode)
{
	if (keycode == 0)
		return (&move_left);
	if (keycode == 2)
		return (&move_right);
	if (keycode == 1 || keycode == 125)
		return (&move_backwards);
	if (keycode == 13 || keycode == 126)
		return (&move_forward);
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

	action = get_action_function(keycode);
	if (action)
		action(data);
	return (0);
}

int	player_stop_movement(int keycode, t_data *data)
{
	keycode++;
	data->player.movement.x = 0;
	data->player.movement.y = 0;
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

