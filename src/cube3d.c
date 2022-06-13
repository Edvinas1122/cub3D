#include "cube3d.h"

static void	control_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 0, player_action, data);
	mlx_hook(data->mlx.win, 17, 0L, red_x_win, data);
	//mlx_key_hook(data.mlx->win, khook, &data.mlx);
	//mlx_mouse_hook(data.mlx->win, mhook, &data.mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0); //return error
	constructor(&data, argv);
	control_hooks(&data);
	mlx_loop_hook(data.mlx.ptr, render_display, (void *)&data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
