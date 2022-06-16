#include "utils.h"

static int	*getpxl2(t_tmp_video *img, int x, int y)
{
	int	*pos;

	pos = (int *)(img->img_data + (y * img->img_sl +
								x * (img->img_bp / 8)));
	return (pos);
}

static t_color	*set_color_fstr2(t_tmp_video *img, int x, int y)
{
	return ((t_color *)getpxl2(img, x, y));
}

/*
	creates the color matrix for an xpm texture file
*/
static t_color	***create_color_matrix2(int width, int height, t_tmp_video *img)
{
	t_color	***cmatrix;

	cmatrix = calloc(sizeof(t_color **), width + 1);
	int i;
	int j;
	j = 0;
	while (j < width)
	{
		cmatrix[j] = calloc(sizeof(t_color *), height + 1);
		i = 0;
		while (i < height)
		{
			cmatrix[j][i] = set_color_fstr2(img, i, j);
			i++;
		}
		j++;
	}
	return(cmatrix);
}

/*
	opens an xpm file and creates the corresponding color matrix
*/
t_texture	open_texture_xpm2(t_data *data, char *filename)
{
	t_texture	texture;
	t_tmp_video	img;

	texture.img_header = mlx_xpm_file_to_image(data->mlx.ptr, filename, &texture.width, &texture.height);
	if (!texture.img_header)
		destructor(data);
	img.img_data = mlx_get_data_addr(texture.img_header, &img.img_bp, &img.img_sl, &img.img_e);
	texture.matx = create_color_matrix2(texture.width, texture.height, &img);
	return (texture);
}