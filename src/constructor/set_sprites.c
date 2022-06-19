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

static void	set_sprite_images(t_data *data, t_list **file, int *img_ct)
{
	t_list			*row;
	void			*img_header;
	t_tmp_video		img;
	int				i;

	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		img_header = mlx_xpm_file_to_image(data->mlx.ptr, (char *)row->content,
				&data->sprite_images[i].width, &data->sprite_images[i].height);
		if (!img_header)
			destructor(data);
		img.img_data = mlx_get_data_addr(img_header, &img.img_bp, \
										&img.img_sl, &img.img_e);
		printf("\n%s\n", img.img_data);
		data->sprite_images[i].matx = create_color_matrix(\
			data->sprite_images[i].width, data->sprite_images[i].height, &img);
		data->sprite_images[i].img_header = img_header;
		row = row->next;
		i++;
	}
	*img_ct = i;
}

static t_entity	*set_entities(t_list **file, int img_ct)
{
	t_list		*row;
	t_entity	*entity;
	char		**info;
	int			i;

	i = 0;
	row = iterate_sections(file, 2);
	entity = ft_calloc(ft_lstsize(row) + 1, sizeof(t_entity));
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		entity[i].id = ft_atoi(row->content);
		if (img_ct <= entity[i].id)
			entity[i].anim_info = 1;
		info = ft_split(&row->content[(entity[i].id / 10) + 2], ',');
		entity[i].position.x = ft_atoi(info[0]);
		entity[i].position.y = ft_atoi(info[1]);
		entity[i].scale = ft_atoi(info[2]);
		delocate_arr(info);
		row = row->next;
		i++;
	}
	entity->obj_count = i;
	return (entity);
}

static void	set_animation_sprites(t_data *data, t_list **file)
{
	t_list			*row;
	t_tmp_video		img;
	int				i;

	data->sprite_anim = ft_calloc(1 + 1, sizeof(t_sprite_anim));
	data->sprite_anim[0].img_arr = ft_calloc(4 + 1, sizeof(t_texture));
	row = iterate_sections(file, 1);
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		data->sprite_anim[0].img_arr[i].img_header
			= mlx_xpm_file_to_image(data->mlx.ptr, (char *)row->content,
				&data->sprite_anim[0].img_arr[i].width,
				&data->sprite_anim[0].img_arr[i].height);
		if (!data->sprite_anim[0].img_arr[i].img_header)
			destructor(data);
		img.img_data
			= mlx_get_data_addr(data->sprite_anim[0].img_arr[i].img_header,
				&img.img_bp, &img.img_sl, &img.img_e);
		data->sprite_anim[0].img_arr[i].matx
			= create_color_matrix(data->sprite_anim[0].img_arr[i].width,
				data->sprite_anim[0].img_arr[i].height, &img);
		row = row->next;
		i++;
	}
}

void	set_sprites(t_data *data, char *sprite_ini)
{
	t_list	**file;
	int		image_ct;

	file = open_sprite_ini(&data->sprite_images, sprite_ini);
	set_sprite_images(data, file, &image_ct);
	set_animation_sprites(data, file);
	data->entity = set_entities(file, image_ct);
	data->entity_arr = ft_calloc(sizeof(t_entity *),
			data->entity->obj_count + 1);
	data->util.soundtrack = set_soundtrack(file);
	set_minimap_frame(data);
	set_bigmap_background(data);
	lst_clear_2(file);
}
