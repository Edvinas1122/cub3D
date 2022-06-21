/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_single.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:29 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/21 12:36:49 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	mother_ducking_constructor(t_entity ent, t_texture texture, \
													t_draw_entity *draw)
{
	draw->sf = ent.scale / (ent.distance / TILE_SIZE);
	draw->scaledwidth = (int)(texture.width * draw->sf);
	draw->scaledheight = (int)(texture.height * draw->sf);
	draw->xstart = (int)ent.on_screen.x - draw->scaledwidth / 2;
	draw->ystart = (int)ent.on_screen.y - draw->scaledheight;
	draw->distance = ent.distance;
	draw->dim = get_dim_factor(draw->distance);
}

void	color_the_mother_ducking_pixel(t_color ***img, int x, int y, \
													t_draw_entity draw)
{
	t_color	dimmed;

	if (draw.color.a == 0)
	{
		dimmed = dim_color(draw.color, draw.dim);
		pixel_put(img, dimmed, draw.xstart + x, draw.ystart + y);
	}
}

void	draw_the_mother_ducking_line(t_color ***img, t_draw_entity draw, \
										int x, t_color ***matx)
{
	int	y;

	y = 0;
	while (y < draw.scaledheight)
	{
		if (draw.ystart + y >= 0 && draw.ystart + y < SCREEN_HEIGHT)
		{
			draw.color = (*matx[(int)(x / draw.sf)][(int)(y / draw.sf)]);
			color_the_mother_ducking_pixel(img, x, y, draw);
		}
		y++;
	}
}

void	mother_ducking_drawer(t_data *data, t_draw_entity draw, double dist, \
															t_color ***matx)
{
	int	x;

	x = 0;
	while (x < draw.scaledwidth)
	{
		if (draw.xstart + x >= 0 && draw.xstart + x < SCREEN_WIDTH && \
			data->map.z_buffer[draw.xstart + x] > dist)
			draw_the_mother_ducking_line(data->video.img_matrix,
				draw, x, matx);
		x++;
	}
}

void	draw_the_mother_ducking_sprite(t_data *data, t_texture sprite_data, \
															t_entity sprite)
{
	t_draw_entity	draw;

	mother_ducking_constructor(sprite, sprite_data, &draw);
	mother_ducking_drawer(data, draw, sprite.distance, sprite_data.matx);
}
