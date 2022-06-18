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
// static void	draw_player(t_color ***img, t_color color, t_player player, int size)
// {
// 	t_vect cord;

// 	cord.x = (((player.pos.x * 2) - size / 2) / TILE_SIZE);
// 	cord.y = (((player.pos.y * 2) - size / 2) / TILE_SIZE);
// 	draw_box(img, color, cord, size/2);
// }

/**
	Draws a squere of a MINIMAP_SIZE height and width in given cordinate
	that is compencated by MINIMAP_SIZE
	No buffer overstep protection yet
*/
// static void	draw_2d_minimap(t_color ***img, char **bit_map, t_color color[3], int minimap_size)
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

void	display_minimap_frame(t_data *data)
{
	double	scalefactor;
	int		scaledwidth;
	int		scaledheight;
	scalefactor = 1;
	scaledwidth = (int)data->util.minimap_frame->width * scalefactor;
	scaledheight = (int)data->util.minimap_frame->height * scalefactor;
	for (int x = 0; x < scaledwidth; x++)
	{
		{
			for (int y = 0; y < scaledheight; y++)
			{
				if (data->util.minimap_frame->matx[(int)(y/scalefactor)][(int)(x/scalefactor)]->a == 0)
					pixel_put(data->video.img_matrix, *data->util.minimap_frame->matx[(int)(y/scalefactor)][(int)(x/scalefactor)], x, y);
			}
		}
	}
}

void	draw_2d_minimap_small(t_data *data)
{
	int	x;
	int	y;
	int	bmp_x;
	int	bmp_y;
	t_color black;
	black.a = 0;
	black.r = 0;
	black.g = 0;
	black.b = 0;
	// bmp_y = 0;
	y = 0;
	while (y < 194)
	{
		x = 0;
		while (x < 195)
		{
			pixel_put(data->video.img_matrix, black, x+30, y+29);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < 174)
	{
		bmp_y = (int)(data->player.pos.y - 350 + y*4);
		if (bmp_y >= 0)
			bmp_y /= TILE_SIZE;
		if (bmp_y > 0 && !data->map.bit_map[bmp_y])
			break ;
		x = 0;
		if (bmp_y >= 0 && data->map.bit_map[bmp_y])
		{
			while (x < 175)
			{
				bmp_x = (int)(data->player.pos.x - 350 + x*4);
				if (bmp_x >= 0)
					bmp_x /= TILE_SIZE;
				if (bmp_x > 0 && !data->map.bit_map[bmp_y][bmp_x])
					break ;
				// if (bmp_x == 1 || bmp_x == 0 || bmp_y == 0 || bmp_x == 0)
					// printf("%d %d %c\n", bmp_x, bmp_y, data->map.bit_map[bmp_y][bmp_x]);
				if (bmp_x >= 0 && data->map.bit_map[bmp_y][bmp_x])
				{
					if (data->map.bit_map[bmp_y][bmp_x] == '1')
						pixel_put(data->video.img_matrix, data->util.minimap[0], x+40, y+39);
					else if (data->map.bit_map[bmp_y][bmp_x] == '2')
						pixel_put(data->video.img_matrix, data->util.minimap[2], x+40, y+39);
					else if (data->map.bit_map[bmp_y][bmp_x] != ' ')
						pixel_put(data->video.img_matrix, data->util.minimap[1], x+40, y+39);
				}
				x++;
			}
		}
		y++;
	}
}

// void	draw_2d_minimap_small(t_data *data)
// {
// 	double	x;
// 	double	y;
// 	int		i_x;
// 	int		i_y;
// 	char	**bit_map;
// 	int		pxl_x, pxl_y;

// 	bit_map = data->map.bit_map;
// 	x = data->player.pos.x - 350;
// 	while (x < data->player.pos.x + 349)
// 	{
// 		y = data->player.pos.y - 350;
// 		while (y < data->player.pos.y + 349)
// 		{
// 			if (x > 0 && y > 0)
// 			{
// 				i_x = (int)x/TILE_SIZE;
// 				i_y = (int)y/TILE_SIZE;
// 				pxl_x = (int)((x + 350 - data->player.pos.x)/4) + 40;
// 				pxl_y = (int)((y + 350 - data->player.pos.y)/4) + 40;
// 				// printf("%d %d\n", i_x, i_y);
// 				// printf("%d %d\n", pxl_x, pxl_y);
// 				// printf("%d %d\n", i_y, i_x);
// 				if (!bit_map[i_y] || !bit_map[i_y][i_x])
// 				{
// 					y++;
// 				 	continue ;
// 				}
// 				if (bit_map[i_y] && bit_map[i_y][i_x])
// 				{
// 					// printf("%d %d\n", i_y, i_x);
// 					if (bit_map[i_y][i_x] == '1')
// 						pixel_put(data->video.img_matrix, data->util.minimap[0], pxl_x, pxl_y);
// 					else if (bit_map[i_y][i_x] == '2')
// 						pixel_put(data->video.img_matrix, data->util.minimap[2], pxl_x, pxl_y);
// 					else
// 						pixel_put(data->video.img_matrix, data->util.minimap[1], pxl_x, pxl_y);
// 				}
// 				// printf("%f %f\n", x, y);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

static void	draw_player_small(t_color ***img, t_color color)
{
	int i;
	int	i2;

	i = 0;
	while (i < 10)
	{
		i2 = 0;
		while (i2 < 10)
		{
			pixel_put(img, color, 121 + i, 121 + i2);
			i2++;
		}
		i++;
	}
}


void	display_minimap(t_data *data)
{
	// draw_2d_minimap(data->video.img_matrix, data->map.bit_map,
	// 				data->util.minimap, data->util.minimap_size);
	draw_2d_minimap_small(data);
	draw_player_small(data->video.img_matrix, data->util.minimap[3]);
	// draw_player(data->video.img_matrix, data->util.minimap[3],
	// 			data->player, data->util.minimap_size);
	display_minimap_frame(data);
}
