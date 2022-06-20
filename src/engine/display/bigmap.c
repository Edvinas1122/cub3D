/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:42 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:04:43 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		y = 0;
		while (y < (int)bg.height * sf * 1.5)
		{
			color = bg.matx[(int)(x / (sf * 1.5))][(int)(y / (sf * 1.5))];
			if (color->a == 0)
				pixel_put(img, *color, scaledstartx + x, scaledstarty + y);
			y++;
		}
		x++;
	}
}

void	draw_player_box(t_data *data, int x, int y)
{
	int	size;
	int	i;
	int	j;

	i = x;
	size = 10 * data->util.map_scale / 25;
	while (i < size + x)
	{
		j = y;
		while (j < size + y)
		{
			pixel_put(data->video.img_matrix, data->util.minimap[3], i, j);
			j++;
		}
		i++;
	}
}

void	draw_player_big(t_data *data, t_vect pos)
{
	int	bmp_x;
	int	bmp_y;
	int	draw_x;
	int	draw_y;
	int	size;

	size = 10 * data->util.map_scale / 25;
	bmp_x = pos.x / TILE_SIZE;
	bmp_y = pos.y / TILE_SIZE;
	draw_x = bmp_x * data->util.map_scale + data->util.map_offset_x;
	draw_y = bmp_y * data->util.map_scale + data->util.map_offset_y;
	draw_x += (data->util.map_scale * fmod(pos.x, TILE_SIZE)) / TILE_SIZE;
	draw_y += (data->util.map_scale * fmod(pos.y, TILE_SIZE)) / TILE_SIZE;
	draw_x -= size / 2;
	draw_y -= size / 2;
	draw_player_box(data, draw_x, draw_y);
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
