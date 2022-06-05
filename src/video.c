#include "cube3d.h"

static int	fillmatrix(t_args *mlx)
{
	int		row;
	int		col;

	row = -1;
	col = -1;
	while (++row < mlx->img_size)
	{
		while (++col < mlx->img_size)
		{
            (mlx->img_matrix)[row][col][0] = (char)255;
            (mlx->img_matrix)[row][col][1] = (char)255;
            (mlx->img_matrix)[row][col][2] = (char)255;
            (mlx->img_matrix)[row][col][3] = 0;
		}
		col = -1;
	}
	return (0);
}

static char	***creatematrix(char *img, int img_size, int img_sl)
{
	int		i;
	char	*ptr;
	char	**pptr;
	char	***ppptr;

	ptr = img;
	pptr = malloc(sizeof(char *) * img_size * img_size);
	i = 0;
	while (ptr < (img + img_size * img_sl))
	{
		pptr[i++] = ptr;
		ptr = ptr + 4;
	}
	i = 0;
	ppptr = malloc(img_size * sizeof(char **));
	i = img_size - 1;
	while (i >= 0)
	{
		ppptr[i--] = pptr;
		pptr = pptr + img_size;
	}
	return (ppptr);
}

t_video	*createwindow(int argc, char *argv[])
{
    argc++;
    (void) argv;
	t_args	*x;

	x = malloc(sizeof(t_args));
	x->img_size = 500;
	x->mlx_ptr = mlx_init();
	x->img_ptr = mlx_new_image(x->mlx_ptr, x->img_size, x->img_size);
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->img_size, x->img_size, "cube3d");
	x->img = mlx_get_data_addr(x->img_ptr, &x->img_bp, &x->img_sl, &x->img_e);
	x->img_matrix = creatematrix(x->img, x->img_size, x->img_sl);
	fillmatrix(x);
	return (x);
}