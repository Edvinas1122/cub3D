#include "display.h"

static int	get_bmp_pos(int n, double player_n, double sf)
{
	double	d_tmp;
	int		bmp_n;

	d_tmp = player_n - (350 * sf) + (n * 4);
	if (d_tmp < 0)
		return (-1);
	bmp_n = (int)d_tmp / TILE_SIZE;
	return (bmp_n);
}

static void	choose_minimap_color(t_data *data, char mapcharacter, int x, int y)
{
	if (mapcharacter == '1')
		pixel_put(data->video.img_matrix, data->util.minimap[0], x, y);
	else if (mapcharacter == '2')
		pixel_put(data->video.img_matrix, data->util.minimap[2], x, y);
	else if (mapcharacter != ' ')
		pixel_put(data->video.img_matrix, data->util.minimap[1], x, y);
}

static void	draw_2d_minimap_line(t_data *data, int y, int bmp_y, double sf)
{
	int	x;
	int	bmp_x;

	x = 0;
	while (x < 175 * sf)
	{
		bmp_x = get_bmp_pos(x, data->player.pos.x, data->scalefactor);
		if (bmp_x > 0 && !data->map.bit_map[bmp_y][bmp_x])
			break ;
		if (bmp_x >= 0 && data->map.bit_map[bmp_y][bmp_x])
			choose_minimap_color(data, data->map.bit_map[bmp_y][bmp_x], \
											x + (40 * sf), y + (39 * sf));
		x++;
	}
}

void	draw_2d_minimap_small(t_data *data, double sf)
{
	int	y;
	int	bmp_y;

	y = 0;
	while (y < 174 * sf)
	{
		bmp_y = get_bmp_pos(y, data->player.pos.y, data->scalefactor);
		if (bmp_y > 0 && !data->map.bit_map[bmp_y])
			break ;
		if (bmp_y >= 0 && data->map.bit_map[bmp_y])
			draw_2d_minimap_line(data, y, bmp_y, sf);
		y++;
	}
}
