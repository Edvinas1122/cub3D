#include "constructor.h"

static int	fillmatrix(t_color ***img_matrix)
{
	int		row;
	int		col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
            (img_matrix)[row][col]->a = (char)0;
            (img_matrix)[row][col]->r = (char)255;
            (img_matrix)[row][col]->g = (char)255;
            (img_matrix)[row][col]->b = (char)255;
			col++;
		}
		row++;
	}
	return (0);
}

/*
	Links row to img_data row representing address
	Links row's members with img_data row's members
*/
static void	link_to_img_row(t_color **row, char *img_data, int width, int i)
{
	int	i2;
	int	offset;

	offset = width * i * 4;
	i2 = 0;
	while (i2 < width)
	{
		row[i2] = (t_color *)&img_data[offset + (i2 * 4)];
		i2++;
	}
}

/**
	@brief Create a 2D array or t_color that is dirrectly linked to img_data
	for array methods of accessing memory of an image -> pixels -> colors
*/
static t_color	***create_matrix(char *img_data, int width, int height)
{
	t_color	***array;
	int		i;

	i = 0;
	array = ft_calloc(height + 1, sizeof(t_color **));
	while (height > i)
	{
		array[i] = ft_calloc(width + 1, sizeof(t_color *));
		link_to_img_row(array[i], img_data, width, i);
		i++;
	}
	return (array);
}

/*
	initiates video struct - sets image color to black, puts it on screen
*/
t_video	set_video_window(t_mlx mlx)
{
	t_video		video;
	t_tmp_video	tmp;

	video.img = mlx_new_image(mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	tmp.img_data = mlx_get_data_addr(video.img, &tmp.img_bp, &tmp.img_sl, &tmp.img_e);
	video.img_matrix = create_matrix(tmp.img_data, SCREEN_WIDTH, SCREEN_HEIGHT);
	fillmatrix(video.img_matrix);
	return (video);
}
