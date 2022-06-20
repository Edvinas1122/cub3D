/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures_xmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:18 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:04:19 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;
	int		j;

	cmatrix = calloc(sizeof(t_color **), height + 1);
	j = 0;
	while (j < height)
	{
		cmatrix[j] = calloc(sizeof(t_color *), width + 1);
		i = 0;
		while (i < width)
		{
			cmatrix[j][i] = set_color_fstr(img, j, i);
			i++;
		}
		j++;
	}
	return (cmatrix);
}

/*
	opens an xpm file and creates the corresponding color matrix
*/
t_texture	open_texture_xpm(t_data *data, char *file)
{
	t_texture	txtr;
	t_tmp_video	img;
	void		*imgptr;

	imgptr = mlx_xpm_file_to_image(data->mlx.ptr, \
						file, &txtr.width, &txtr.height);
	if (!imgptr)
		destructor(data);
	img.img_data = mlx_get_data_addr(imgptr, &img.img_bp, \
								&img.img_sl, &img.img_e);
	txtr.matx = create_color_matrix(txtr.height, txtr.width, &img);
	txtr.img_header = imgptr;
	return (txtr);
}

/*
	opens texture files and loads them into the map struct
*/
t_texture	load_texture_files(t_data *data, char *filename)
{
	return (open_texture_xpm(data, filename));
}
