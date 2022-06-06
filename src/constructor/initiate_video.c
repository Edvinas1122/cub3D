#include "constructor.h"

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
            (mlx->img_matrix)[row][col][0] = (char)0;
            (mlx->img_matrix)[row][col][1] = (char)0;
            (mlx->img_matrix)[row][col][2] = (char)0;
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

t_video	*set_video_window(t_mlx *mlx)
{
	t_video	*video;

	video = malloc(sizeof(t_video));
	video->img_ptr = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	video->img = mlx_get_data_addr(video->img_ptr, &video->img_bp, &video->img_sl, &video->img_e);
	video->img_matrix = creatematrix(video->img, SCREEN_WIDTH, SCREEN_HEIGHT);
	fillmatrix(video);
	return (video);
}
