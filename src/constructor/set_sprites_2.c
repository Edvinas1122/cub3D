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
	data->util.minimap_frame = open_texture_xpm(data, \
						"./assets/minimap_frame_LR.xpm");
}

void	set_bigmap_background(t_data *data)
{
	data->util.bigmap_background = open_texture_xpm(data, \
						"./assets/bigmap_background.xpm");
}

char	*set_soundtrack(t_list **file)
{
	t_list	*row;

	row = iterate_sections(file, 3);
	return (ft_strdup(row->content));
}
