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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
		return (0); //return error
	constructor(&data, argv);
	mlx_put_image_to_window(data.mlx->ptr, data.mlx->win, data.video->img_ptr, 0, 0);
	// mlx_hook(data.mlx->win, 17, 0L, close_win, x);
	mlx_key_hook(data.mlx->win, khook, x);
	mlx_mouse_hook(data.mlx->win, mhook, x);
	mlx_loop(data.mlx->ptr);
	return (0);
}
