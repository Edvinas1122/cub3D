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
	char			*img;
	int				i;

	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
	{
		img = mlx_xpm_file_to_image(data->mlx.ptr, row->content,
				&data->sprite_images[i].width, &data->sprite_images[i].height);
		data->sprite_images[i].img_matrix = create_pixel_matrix(img,
				data->sprite_images[i].width, data->sprite_images[i].height);
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

	row = *file;
	i = 0;
	while (ft_strncmp(row->content, "\0\0", 2))
		row = row->next;
	row = row->next;
	sprites = ft_calloc(ft_lstsize(row) + 1, sizeof(t_sprite));
	while (row)
	{
		sprites[i].id = ft_atoi(row->content);
		info = ft_split(&row->content[(sprites[i].id % 10) + 1], ',');
		sprites[i].position.x = ft_atoi(info[0]);
		sprites[i].position.y = ft_atoi(info[1]);
		sprites[i].scale = ft_atoi(info[2]);
		row = row->next;
		i++;
	}
	return (sprites);
}

void set_sprites(t_data *data, char *sprite_ini)
{
	t_list	**file;

	file = open_sprite_ini(&data->sprite_images, sprite_ini);
	set_sprite_images(data, file);
	data->sprite_objects = set_sprite_objects(file);
}