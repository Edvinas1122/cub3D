#include "constructor.h"

void	destroy_mtrx_image(t_color ***matrix, char *img)
{
	int y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	if (img)
		free(img);
	//mlx_destroy_image(data->mlx.ptr, data->video.img);
}

void	destructor(t_data *data)
{
	if (data->map.bit_map)
		free(data->map.bit_map);
	if (data->video.img)
		destroy_mtrx_image(data->video.img_matrix, data->video.img);
	if (data->map.north.matx)
		destroy_mtrx_image(data->map.north.matx, NULL);
	if (data->map.east.matx)
		destroy_mtrx_image(data->map.east.matx, NULL);
	if (data->map.west.matx)
		destroy_mtrx_image(data->map.west.matx, NULL);
	if (data->map.south.matx)
		destroy_mtrx_image(data->map.south.matx, NULL);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	free(data->mlx.ptr);
	end_audio();
	exit(0);
}
