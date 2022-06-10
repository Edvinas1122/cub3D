#include "control.h"

// int	close_win(void *param)
// {
// 	t_args	*x;

// 	write(1, "hello\n", 6);
// 	x = (t_args *) param;
// 	x->img_e = 10;
// 	mlx_destroy_image(x->mlx_ptr, x->img_ptr);
// 	mlx_destroy_window(x->mlx_ptr, x->win_ptr);
// 	mlx_loop_end(x->mlx_ptr);
// 	free(x->img_matrix[x->img_size - 1]);
// 	free(x->img_matrix);
// 	free(x->mlx_ptr);
// 	free(x);
// 	exit(1);
// 	return (0);
// }

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

// static void	*get_action_function(int keycode, t_data *data)
// {
// 	if (keycode == 0)
// 		move_left(data);
// 	else if (keycode == 2)
// 		move_right(data);
// 	else if (keycode == 1 || keycode == 125)
// 		move_backwards(data);
// 	else if (keycode == 13 || keycode == 126)
// 		move_forward(data);
// 	else if (keycode == 123)
// 		rotate_player_left(data);
// 	else if (keycode == 124)
// 		rotate_player_right(data);
// 	return (NULL);
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
