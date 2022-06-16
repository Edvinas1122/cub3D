#include "cube3d.h"

static void	control_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 0, player_action, data);
	mlx_hook(data->mlx.win, 3, 0, player_stop_movement, data);
	mlx_hook(data->mlx.win, 17, 0L, red_x_win, data);
	mlx_hook(data->mlx.win, 6, (1L<<6), player_mouse_action, data);
	mlx_mouse_move(data->mlx.win, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_mouse_hide(data->mlx.win, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		ft_putstr_fd("No map input", 1);
		return (0);
	}
	constructor(&data, argv);
	control_hooks(&data);
	play_audio(data.util.soundtrack);
	mlx_loop_hook(data.mlx.ptr, engine, (void *)&data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
