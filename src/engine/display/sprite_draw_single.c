#include "display.h"

static void	ducking_constructor(t_texture sprite_data, t_entety sprite, t_dis_draw_spr *tmp)
{
	tmp->scalefactor = sprite.scale / (sprite.distance / TILE_SIZE);
	tmp->scaledwidth = (int)(sprite_data.width * tmp->scalefactor);
	tmp->scaledheight = (int)(sprite_data.height * tmp->scalefactor);
	tmp->xstart = (int)sprite.on_screen.x - tmp->scaledwidth/2;
	tmp->ystart = (int)sprite.on_screen.y - tmp->scaledheight;
}

static void	draw_the_ducking_line(t_data *data, t_texture sprite_data, t_entety sprite, t_dis_draw_spr	tmp, int x)
{
	double	dimfactor;
	int		j;
	t_color	dimmed;

	j = 0;
	while (j < tmp.scaledheight)
	{
		if (tmp.ystart + j >= 0 &&tmp.ystart + j < SCREEN_HEIGHT)
		{
			if ((*sprite_data.matx[(int)(x/tmp.scalefactor)][(int)(j/tmp.scalefactor)]).a == 0)
			{
				dimfactor = get_dim_factor(sprite.distance);
				dimmed = dim_color(*sprite_data.matx[(int)(x/tmp.scalefactor)][(int)(j/tmp.scalefactor)], dimfactor);
				pixel_put(data->video.img_matrix, dimmed, tmp.xstart + x, tmp.ystart + j);
			}
		j++;
	}
}

void	draw_the_mother_ducking_sprite(t_data *data, t_texture sprite_data, t_entety sprite)
{
	t_dis_draw_spr	tmp;
	int				x;

	ducking_constructor(sprite_data, sprite, &tmp);
	x = 0;
	while (x < tmp.scaledwidth)
	{
		if (tmp.xstart + x >= 0 && tmp.xstart + x < SCREEN_WIDTH
				&& data->map.z_buffer[tmp.xstart + x] > sprite.distance)
			draw_the_ducking_line(data, sprite_data, sprite, tmp, x);
		x++;
	}
}
