#include "constructor.h"

static int	validate_name_ends(t_list **file)
{
	int 	len;
	t_list	*row;
	int		i;

	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2) && row)
	{
		len = ft_strlen(row->content);
		if (len < 5 || ft_strncmp(&row->content[len - 4], ".xpm\0", 5))
			return (0);
		row = row->next;
		i++;
	}
	return (i);
}

static t_list	**open_sprite_ini(t_sprite_data **sprites, char *sprite_ini)
{
	t_list	**file;
	int		num_of_sprites;

	if (!file_to_heap(sprite_ini, &file))
	{
		ft_putstr_fd("sprite_info.ini open error", 1);
		return (NULL);
	}
	num_of_sprites = validate_name_ends(file);
	if (!num_of_sprites)
		return (0);
	*sprites = ft_calloc(num_of_sprites + 1, sizeof(t_sprite_data));
	return (file);
}

static void	set_sprite_images(t_data *data, t_list **file)
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
		img.img_data = mlx_get_data_addr(img_header, &img.img_bp, &img.img_sl, &img.img_e);
		printf("\n%s\n", img.img_data);
		data->sprite_images[i].img_matrix = create_color_matrix(data->sprite_images[i].width, data->sprite_images[i].height, &img);
		row = row->next;
		i++;
	}
}

static t_sprite	*set_sprite_objects(t_list **file)
{
	t_list		*row;
	t_sprite	*sprites;
	char		**info;
	int			i;
	int			*obj_count;

	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	sprites = ft_calloc(ft_lstsize(row) + 1, sizeof(t_sprite));
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		sprites[i].id = ft_atoi(row->content);
		info = ft_split(&row->content[(sprites[i].id / 10) + 2], ',');
		sprites[i].position.x = ft_atoi(info[0]);
		sprites[i].position.y = ft_atoi(info[1]);
		sprites[i].scale = ft_atoi(info[2]);
		row = row->next;
		i++;
	}
	obj_count = malloc(sizeof(int));
	*obj_count = i;
	sprites->obj_count = obj_count;
	return (sprites);
}

static char	*set_soundtrack(t_list **file)
{
	t_list	*row;

	row = *file;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	return (ft_strdup(row->content));
}

static void	set_entety_imgaes(t_data *data, t_list **file)
{
	t_list			*row;
	void			*img_header;
	t_tmp_video		img;
	int				i;

	data->sprite_anim = ft_calloc(1 + 1, sizeof(t_sprite_anim));
	data->sprite_anim[0].img_matrix = ft_calloc(4 + 1, sizeof(t_color ***));
	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		img_header = mlx_xpm_file_to_image(data->mlx.ptr, (char *)row->content,
				&data->sprite_anim[0].width, &data->sprite_anim[0].height);
		if (!img_header)
			destructor(data);
		img.img_data = mlx_get_data_addr(img_header, &img.img_bp, &img.img_sl, &img.img_e);
		data->sprite_anim[0].img_matrix[i] = create_color_matrix(data->sprite_anim[0].width, data->sprite_anim[0].height, &img);
		row = row->next;
		i++;
	}
}

void	set_minimap_frame(t_data *data)
{
	void		*img_header;
	t_tmp_video	img;

	data->util.minimap_frame = ft_calloc(sizeof(t_sprite_data), 1);
	img_header = mlx_xpm_file_to_image(data->mlx.ptr, "./assets/minimap_frame_LR.xpm", &data->util.minimap_frame->width, &data->util.minimap_frame->height);
	img.img_data = mlx_get_data_addr(img_header, &img.img_bp, &img.img_sl, &img.img_e);
	data->util.minimap_frame->img_matrix = create_color_matrix(data->util.minimap_frame->width, data->util.minimap_frame->height, &img);
}

void	draw_minimap_new()
{
	int x;
	int y;

	x = 0;
	y = 0;
}


void set_sprites(t_data *data, char *sprite_ini)
{
	t_list	**file;

	file = open_sprite_ini(&data->sprite_images, sprite_ini);
	set_sprite_images(data, file);
	set_entety_imgaes(data, file);
	data->sprite_objects = set_sprite_objects(file);
	data->sprite_arr = ft_calloc(sizeof(t_sprite *), *(data->sprite_objects->obj_count) + 1);
	data->util.soundtrack = set_soundtrack(file);
	set_minimap_frame(data);
}