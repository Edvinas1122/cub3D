#include "constructor.h"

static t_list	*iterate_sections(t_list **file, int i)
{
	t_list		*row;

	row = *file;
	while (i--)
	{
		while (ft_strncmp(row->content, "\0\0", 2))
			row = row->next;
		row = row->next;
	}
	return (row);
}

void	set_minimap_frame(t_data *data)
{
	void		*img_header;
	t_tmp_video	img;

	data->util.minimap_frame = ft_calloc(sizeof(t_texture), 1);
	img_header = mlx_xpm_file_to_image(data->mlx.ptr,
			"./assets/minimap_frame_LR.xpm", &data->util.minimap_frame->width,
			&data->util.minimap_frame->height);
	img.img_data = mlx_get_data_addr(img_header,
			&img.img_bp, &img.img_sl, &img.img_e);
	data->util.minimap_frame->matx
		= create_color_matrix(data->util.minimap_frame->height, \
		data->util.minimap_frame->width, &img);
}

void	set_bigmap_background(t_data *data)
{
	void		*img_header;
	t_tmp_video	img;

	data->util.bigmap_background = ft_calloc(sizeof(t_texture), 1);
	img_header = mlx_xpm_file_to_image(data->mlx.ptr, \
		"./assets/bigmap_background.xpm", \
		&data->util.bigmap_background->width, \
		&data->util.bigmap_background->height);
	img.img_data = mlx_get_data_addr(img_header,
			&img.img_bp, &img.img_sl, &img.img_e);
	data->util.bigmap_background->matx
		= create_color_matrix(data->util.bigmap_background->height, \
		data->util.bigmap_background->width, &img);
}

char	*set_soundtrack(t_list **file)
{
	t_list	*row;

	row = iterate_sections(file, 3);
	return (ft_strdup(row->content));
}
