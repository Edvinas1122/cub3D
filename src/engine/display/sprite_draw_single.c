#include "display.h"

static double	get_dim_factor(double distance)
{
	double factor;

	factor = distance/1000;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	return (factor);
}

void	draw_the_mother_ducking_sprite(t_data *data, t_texture sprite_data, t_entety sprite)
{
	double	scalefactor;
	int		scaledwidth;
	int		scaledheight;
	int		xstart;
	int		ystart;

	scalefactor = sprite.scale / (sprite.distance / TILE_SIZE);
	scaledwidth = (int)(sprite_data.width * scalefactor);
	scaledheight = (int)(sprite_data.height * scalefactor);
	xstart = (int)sprite.on_screen.x - scaledwidth/2;
	ystart = (int)sprite.on_screen.y - scaledheight;
	for (int x = 0; x < scaledwidth; x++)
	{
		if  (xstart + x >= 0 && xstart + x < SCREEN_WIDTH && data->map.z_buffer[xstart + x] > sprite.distance) //checking if wall at this column is closer, and if it's offscreen
		{
			for (int j = 0; j < scaledheight; j++)
				if (ystart + j >= 0 &&ystart + j < SCREEN_HEIGHT)	//checking if y val is offscreen
				{
					double dimfactor;
					if ((*sprite_data.matx[(int)(x/scalefactor)][(int)(j/scalefactor)]).a == 0) //not drawing if transparency value isn't 0
					{
						t_color dimmed;
						dimfactor = get_dim_factor(sprite.distance);
						dimmed = dim_color(*sprite_data.matx[(int)(x/scalefactor)][(int)(j/scalefactor)], dimfactor);
						pixel_put(data->video.img_matrix, dimmed, xstart + x, ystart + j);
					}
				}
		}
	}
}