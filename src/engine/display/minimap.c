#include "display.h"

/*
	Draws box of a given color of a given size from a given pixel coordinate
// */
// static void	draw_box(t_color ***img, t_color color, t_vect cord, int size)
// {
// 	int i;
// 	int	i2;

// 	i = 0;
// 	while (i < size)
// 	{
// 		i2 = 0;
// 		while (i2 < size)
// 		{
// 			pixel_put(img, color, (cord.x * size) + i, 
// 						(cord.y * size) + i2);
// 			i2++;
// 		}
// 		i++;
// 	}
// }

/*
	Draws player cube
*/
// static void	draw_player(t_color ***img, t_color color,
// 	t_player player, int size)
// {
// 	t_vect	cord;

// 	cord.x = (((player.pos.x * 2) - size / 2) / TILE_SIZE);
// 	cord.y = (((player.pos.y * 2) - size / 2) / TILE_SIZE);
// 	draw_box(img, color, cord, size / 2);
// }

/**
	Draws a squere of a MINIMAP_SIZE height and width in given cordinate
	that is compencated by MINIMAP_SIZE
	No buffer overstep protection yet
*/
// static void	draw_2d_minimap(t_color ***img, char **bit_map,
//	t_color color[3], int minimap_size)
// {
// 	t_vect	cord;

// 	cord.y = 0;
// 	while (bit_map[(int)cord.y])
// 	{
// 		cord.x = 0;
// 		while (bit_map[(int)cord.y][(int)cord.x])
// 		{
// 			if (bit_map[(int)cord.y][(int)cord.x] == '1')
// 				draw_box(img, color[0], cord, minimap_size);
// 			else if (bit_map[(int)cord.y][(int)cord.x] == '2')
// 				draw_box(img, color[2], cord, minimap_size);
// 			else if (bit_map[(int)cord.y][(int)cord.x] != ' ')
// 				draw_box(img, color[1], cord, minimap_size);
// 			cord.x++;
// 		}
// 		cord.y++;
// 	}
// }

void	display_minimap_frame(t_texture *frame, t_color ***img, double sf)
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

static void	choose_minimap_color(t_data *data, char mapcharacter, int x, int y)
{
	if (mapcharacter == '1')
		pixel_put(data->video.img_matrix, data->util.minimap[0], x, y);
	else if (mapcharacter == '2')
		pixel_put(data->video.img_matrix, data->util.minimap[2], x, y);
	else if (mapcharacter != ' ')
		pixel_put(data->video.img_matrix, data->util.minimap[1], x, y);
}

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

void	display_minimap(t_data *data)
{
	// draw_2d_minimap(data->video.img_matrix, data->map.bit_map,
	// 				data->util.minimap, data->util.minimap_size);
	// draw_player(data->video.img_matrix, data->util.minimap[3],
	// 			data->player, data->util.minimap_size);
	draw_minimap_background(data->video.img_matrix, data->util.minimap[4], \
															data->scalefactor);
	draw_2d_minimap_small(data, data->scalefactor);
	draw_player_small(data->video.img_matrix, data->util.minimap[3], \
															data->scalefactor);
	display_minimap_frame(data->util.minimap_frame, data->video.img_matrix, \
															data->scalefactor);
}
