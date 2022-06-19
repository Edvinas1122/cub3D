#include "constructor.h"

void	destroy_mtrx_image(t_data *data, t_texture texture)
{
	int		y;
	t_color	***matrix;

	y = 0;
	matrix = texture.matx;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	mlx_destroy_image(data->mlx.ptr, texture.img_header);
}

static void	destroy_wall_textures(t_data *data)
{
	if (data->map.north.matx)
		destroy_mtrx_image(data, data->map.north);
	if (data->map.east.matx)
		destroy_mtrx_image(data, data->map.east);
	if (data->map.west.matx)
		destroy_mtrx_image(data, data->map.west);
	if (data->map.south.matx)
		destroy_mtrx_image(data, data->map.south);
}

void	destructor(t_data *data)
{
	if (data->map.bit_map)
		free(data->map.bit_map);
	if (data->video.img)
		destroy_mtrx_image(data, data->video);
	destroy_wall_textures(data);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	free(data->mlx.ptr);
	end_audio();
	exit(0);
}
