#include "constructor.h"

int	*getpxl(t_tmp_video *img, int x, int y)
{
	int	*pos;

	pos = (int *)(img->img_data + (y * img->img_sl + \
								x * (img->img_bp / 8)));
	return (pos);
}

t_color	*set_color_fstr(t_tmp_video *img, int x, int y)
{
	return ((t_color *)getpxl(img, x, y));
}

/*
	creates the color matrix for an xpm texture file
*/
t_color	***create_color_matrix(int width, int height, t_tmp_video *img)
{
	t_color	***cmatrix;
	cmatrix = calloc(sizeof(t_color **), height + 1);
	int i;
	int j;
	j = 0;
	while (j < height)
	{
		cmatrix[j] = calloc(sizeof(t_color *), width + 1);
		i = 0;
		while (i < width)
		{
			cmatrix[j][i] = set_color_fstr(img, i, j);
			i++;
		}
		j++;
	}
	return(cmatrix);
}

/*
	opens an xpm file and creates the corresponding color matrix
*/
t_texture	open_texture_xpm(t_data *data, char *filename)
{
	t_texture	texture;
	t_tmp_video	img;
	void		*imgptr;

	imgptr = mlx_xpm_file_to_image(data->mlx.ptr, filename, &texture.width, &texture.height);
	if (!imgptr)
		destructor(data);
	img.img_data = mlx_get_data_addr(imgptr, &img.img_bp, &img.img_sl, &img.img_e);
	texture.matx = create_color_matrix(texture.width, texture.height, &img);
	return (texture);
}

/*
	opens texture files and loads them into the map struct
*/
t_texture	load_texture_files(t_data *data, char *filename)
{
	return (open_texture_xpm(data, filename));
	// map->south = open_texture_xpm(data, data->map, tmp.so);
	// map->west = open_texture_xpm(data, data->map, tmp.we);
	// map->east = open_texture_xpm(data, data->map, tmp.ea);
}

// t_sprite_data	load_sprite_file(t_data *data, char *filename, char *name)
// {
// 	t_sprite_data	sprite_data;
// 	t_tmp_video	img;
// 	void		*imgptr;

// 	// sprite_data = ft_calloc(sizeof(t_sprite_data), 1);
// 	imgptr = mlx_xpm_file_to_image(data->mlx.ptr, filename, &sprite_data.width, &sprite_data.height);
// 	if (!imgptr)
// 		destructor(data);
// 	img.img_data = mlx_get_data_addr(imgptr, &img.img_bp, &img.img_sl, &img.img_e);
// 	sprite_data.img_matrix = create_color_matrix(sprite_data.width, sprite_data.height, &img);
// 	sprite_data.name = ft_strdup(name);
// 	return (sprite_data);
// }

// t_sprite_data	*set_sprite_data(t_data *data)
// {
// 	t_sprite_data *sprite_data;
// 	sprite_data = ft_calloc(sizeof(t_sprite_data), 4);
// 	sprite_data[3] = NULL;
// 	while (1)
// 	sprite_data[0] = load_sprite_file(data, )
// }