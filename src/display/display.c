#include "display.h"

/*
	To fill matrix with color
*/
static int	color_the_matrix(t_color ***img_matrix, int r, int g, int b)
{
	int		row;
	int		col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
            (img_matrix)[row][col]->a = (char)0;
            (img_matrix)[row][col]->r = (char)r;
            (img_matrix)[row][col]->g = (char)g;
            (img_matrix)[row][col]->b = (char)b;
			col++;
		}
		row++;
	}
	return (0);
}

/*
	Renders display
*/
int	render_display(t_data *data)
{
	color_the_matrix(data->video.img_matrix, 255, 0, 0);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->video.img, 0, 0);
	//draw_minimap(data->map, data->video.);

	return (0);
}
