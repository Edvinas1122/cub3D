#include "display.h"

/*
	Draws box of a given color of a given size from a given pixel coordinate
*/
static void	draw_box(t_color ***img, t_color color, t_vect cord, int size)
{
	int i;
	int	i2;

	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			pixel_put(img, color, (cord.x * size) + i, 
						(cord.y * size) + i2);
			i2++;
		}
		i++;
	}
}

/*
	Draws player cube
*/
static void	draw_player(t_color ***img, t_color color, t_player player, int size)
{
	t_vect cord;

	cord.x = (((player.pos.x * 2) - size / 2) / TILE_SIZE);
	cord.y = (((player.pos.y * 2) - size / 2) / TILE_SIZE);
	draw_box(img, color, cord, size/2);
}

/**
	Draws a squere of a MINIMAP_SIZE height and width in given cordinate
	that is compencated by MINIMAP_SIZE
	No buffer overstep protection yet
*/
static void	draw_2d_minimap(t_color ***img, char **bit_map, t_color color[3], int minimap_size)
{
	t_vect	cord;

	cord.y = 0;
	while (bit_map[(int)cord.y])
	{
		cord.x = 0;
		while (bit_map[(int)cord.y][(int)cord.x])
		{
			if (bit_map[(int)cord.y][(int)cord.x] == '1')
				draw_box(img, color[0], cord, minimap_size);
			else if (bit_map[(int)cord.y][(int)cord.x] == '2')
				draw_box(img, color[2], cord, minimap_size);
			else if (bit_map[(int)cord.y][(int)cord.x] != ' ')
				draw_box(img, color[1], cord, minimap_size);
			cord.x++;
		}
		cord.y++;
	}
}

// void	display_minimap_frame(data->video.img_matrix, data->util.minimap_size)

void	display_minimap(t_data *data)
{
	draw_2d_minimap(data->video.img_matrix, data->map.bit_map,
					data->util.minimap, data->util.minimap_size);
	draw_player(data->video.img_matrix, data->util.minimap[3],
				data->player, data->util.minimap_size);
}
