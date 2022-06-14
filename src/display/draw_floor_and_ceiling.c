#include "display.h"

static double	get_dim_factor(int y)
{
	double	factor;

	factor = 1 - ((double)y / (SCREEN_HEIGHT/2));
	factor = factor*factor*factor*factor;
	return (1 - factor);
}

void	draw_floor_and_ceiling(t_data *data)
{
	t_color floor;
	t_color ceiling;
	int		ycount;
	int		xcount;
	double	dimfactor;

	ycount = 0;
	while (ycount < SCREEN_HEIGHT / 2)
	{	
		dimfactor = get_dim_factor(ycount);
		floor = dim_color(data->map.floor, dimfactor);
		ceiling = dim_color(data->map.ceiling, dimfactor);
		xcount = 0;
		while (xcount < SCREEN_WIDTH)
		{
			pixel_put(data->video.img_matrix, floor, xcount, SCREEN_HEIGHT / 2 + ycount);
			pixel_put(data->video.img_matrix, ceiling, xcount, SCREEN_HEIGHT / 2 - ycount - 1);
			xcount++;
		}
		ycount++;
	}
}
