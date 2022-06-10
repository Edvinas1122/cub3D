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
			pixel_put(img, color, (cord.x * MINIMAP_SIZE) + i, 
						(cord.y * MINIMAP_SIZE) + i2);
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

	cord.x = (player.pos.x / TILE_SIZE);
	cord.y = (player.pos.y / TILE_SIZE);
	draw_box(img, color, cord, size);
}

/**
	Draws a squere of a MINIMAP_SIZE height and width in given cordinate
	that is compencated by MINIMAP_SIZE
	No buffer overstep protection yet
*/
static void	draw_2d_minimap(t_color ***img, char **bit_map, t_color color[3])
{
	t_vect	cord;

	cord.y = 0;
	while (bit_map[(int)cord.y])
	{
		cord.x = 0;
		while (bit_map[(int)cord.y][(int)cord.x])
		{
			if (bit_map[(int)cord.y][(int)cord.x] == '1')
				draw_box(img, color[0], cord, MINIMAP_SIZE);
			else
				draw_box(img, color[1], cord, MINIMAP_SIZE);
			cord.x++;
		}
		cord.y++;
	}
}

void	display_minimap(t_data *data)
{
	draw_2d_minimap(data->video.img_matrix, data->map.bit_map,
					data->util.minimap);
	draw_player(data->video.img_matrix, data->util.minimap[2],
				data->player, MINIMAP_SIZE / 2);
}
