#include "constructor.h"

static int	validate_name_ends(t_list **file)
{
	int		len;
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

t_list	**open_sprite_ini(t_texture **sprites, char *sprite_ini)
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
	*sprites = ft_calloc(num_of_sprites + 1, sizeof(t_texture));
	return (file);
}
