#include "display.h"

static void	draw_box(t_data *data, t_color color, int x, int y)
{
	int	i;
	int	j;
	int	size;
	int	draw_x;
	int	draw_y;

	size = data->util.map_scale;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			draw_x = data->util.map_offset_x + i + x;
			draw_y = data->util.map_offset_y + j + y;
			pixel_put(data->video.img_matrix, color, draw_x, draw_y);
			j++;
		}
		i++;
	}
}

void	display_bigmap_background(t_texture bg, t_color ***img, double sf)
{
	int		x;
	int		y;
	int		scaledstartx;
	int		scaledstarty;
	t_color	*color;

	scaledstartx = sf * ((SCREEN_WIDTH - ((int)bg.width * sf * 1.5)) / 2);
	scaledstarty = sf * ((SCREEN_HEIGHT - ((int)bg.height * sf * 1.5)) / 2);
	x = 0;
	while (x < (int)bg.width * sf * 1.5)
	{
		{
			y = 0;
			while (y < (int)bg.height * sf * 1.5)
			{
				color = bg.matx[(int)(x / (sf * 1.5))][(int)(y / (sf * 1.5))];
				if (color->a == 0)
					pixel_put(img, *color, scaledstartx + x, scaledstarty + y);
				y++;
			}
		}
		x++;
	}
}

void	draw_big_map(t_data *data)
{
	int	x;
	int	y;
	int	size;

	size = data->util.map_scale;
	y = 0;
	while (data->map.bit_map[y])
	{
		x = 0;
		while (data->map.bit_map[y][x])
		{
			if (data->map.bit_map[y][x] == '1')
				draw_box(data, data->util.minimap[0], x * size, y * size);
			else if (data->map.bit_map[y][x] == '2')
				draw_box(data, data->util.minimap[2], x * size, y * size);
			else
				draw_box(data, data->util.minimap[1], x * size, y * size);
			x++;
		}
		y++;
	}
}
