#include "cube3d.h"

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

int	khook(int key, void *param)
{
	// t_mlx	mlx;

	// mlx = (t_mlx *) param;
	(void) param;
	if (key == 65307)
	{
		// mlx_destroy_image(mlx->ptr, x->img_ptr);
		// mlx_destroy_window(x->mlx_ptr, x->win_ptr);
		// mlx_loop_end(x->mlx_ptr);
		// free(x->img_matrix[x->img_size - 1]);
		// free(x->img_matrix);
		// free(x->mlx_ptr);
		// free(x);
		exit(1);
	}
	return (0);
}

int	mhook(int button, int x, int y, void *param)
{
    button++;
    x++;
    y++;
	
    (void) param;
	return (0);
}
