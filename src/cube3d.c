#include "cube3d.h"

// static
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

static void	control_hooks(void)
{
	//mlx_hook(data.mlx->win, 17, 0L, close_win, x);
	//mlx_key_hook(data.mlx->win, khook, &data.mlx);
	//mlx_mouse_hook(data.mlx->win, mhook, &data.mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0); //return error
	constructor(&data, argv);
	control_hooks();
	mlx_loop_hook(data.mlx.ptr, render_display, (void *)&data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
