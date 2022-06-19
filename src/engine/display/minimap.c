#include "display.h"

static void	display_minimap_frame(t_texture *frame, t_color ***img, double sf)
{
	int	x;
	int	y;
	int	scaledwidth;
	int	scaledheight;

	scaledwidth = (int)frame->width * sf;
	scaledheight = (int)frame->height * sf;
	x = 0;
	while (x < scaledwidth)
	{
		{
			y = 0;
			while (y < scaledheight)
			{
				if (frame->matx[(int)(y / sf)][(int)(x / sf)]->a == 0)
					pixel_put(img, *frame->matx[(int)(y / sf)][(int)(x / sf)], \
																		x, y);
				y++;
			}
		}
		x++;
	}
}

static void	draw_player_small(t_color ***img, t_color color, double sf)
{
	int	i;
	int	i2;

	i = 0;
	while (i < 10 * sf)
	{
		i2 = 0;
		while (i2 < 10 * sf)
		{
			pixel_put(img, color, (121 * sf) + i, (121 * sf) + i2);
			i2++;
		}
		i++;
	}
}

static void	draw_minimap_background(t_color ***img, t_color color, double sf)
{
	int	y;
	int	x;

	y = 0;
	while (y < 194 * sf)
	{
		x = 0;
		while (x < 195 * sf)
		{
			pixel_put(img, color, x + (30 * sf), y + (29 * sf));
			x++;
		}
		y++;
	}
}

void	draw_box(t_data *data, t_color color, int x, int y)
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

void	display_minimap(t_data *data)
{
		// printf("%d %d\n", data->util.map_offset_x, data->util.map_offset_y);
	if (data->util.minimap_state == 1)
	{
		draw_minimap_background(data->video.img_matrix, data->util.minimap[4], \
															data->scalefactor);
		draw_2d_minimap_small(data, data->scalefactor);
		draw_player_small(data->video.img_matrix, data->util.minimap[3], \
															data->scalefactor);
		display_minimap_frame(data->util.minimap_frame, data->video.img_matrix, \
															data->scalefactor);
	}
	else
	{
		draw_big_map(data);
	}
}
