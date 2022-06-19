#include "display.h"

void	mother_ducking_constructor(t_entety ent, t_texture texture, \
													t_draw_ent *draw_ent)
{
	draw_ent->sf = ent.scale / (ent.distance / TILE_SIZE);
	draw_ent->scaledwidth = (int)(texture.width * draw_ent->sf);
	draw_ent->scaledheight = (int)(texture.height * draw_ent->sf);
	draw_ent->xstart = (int)ent.on_screen.x - draw_ent->scaledwidth / 2;
	draw_ent->ystart = (int)ent.on_screen.y - draw_ent->scaledheight;
	draw_ent->distance = ent.distance;
}

static void	mother_ducking_line_drawer(t_draw_ent *draw_ent, int x, \
										t_color ***img, t_color ***matx)
{
	int	y;

	y = 0;
	while (y < draw_ent->scaledheight)
	{
		if (draw_ent->ystart + y >= 0 && draw_ent->ystart + y < SCREEN_HEIGHT)
		{
			draw_ent->color = \
					*matx[(int)(x / draw_ent->sf)][(int)(y / draw_ent->sf)];
			if (draw_ent->color.a == 0)
			{
				draw_ent->dim = get_dim_factor(draw_ent->distance);
				draw_ent->color = dim_color(draw_ent->color, draw_ent->dim);
				pixel_put(img, draw_ent->color, draw_ent->xstart + x, \
													draw_ent->ystart + y);
			}
		}
		y++;
	}
}

void	draw_the_mother_ducking_sprite(t_data *data, t_texture sprite_data, \
															t_entety sprite)
{
	t_draw_ent	draw_ent;
	int			x;
	double		z_buf;

	mother_ducking_constructor(sprite, sprite_data, &draw_ent);
	x = 0;
	while (x < draw_ent.scaledwidth)
	{
		z_buf = data->map.z_buffer[draw_ent.xstart + x];
		if (draw_ent.xstart + x >= 0 && draw_ent.xstart + x < SCREEN_WIDTH && \
			z_buf > sprite.distance)
			mother_ducking_line_drawer(&draw_ent, x, \
				data->video.img_matrix, sprite_data.matx);
		x++;
	}
}
