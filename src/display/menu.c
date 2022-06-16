#include "display.h"

// static void	copy_the_matrix(t_color ***img_matrix, t_texture texture)
// {
// 	int	row;
// 	int	col;
// 	// double	vertical_factor;
// 	// double	horizontal_factor;

// 	// vertical_factor = (double)SCREEN_WIDTH / texture.width;
// 	// horizontal_factor = (double)SCREEN_HEIGHT / texture.height;
// 	printf("\nwidth :%i\n", texture.width);
// 	printf("\nheight: %i\n", texture.height);
// 	row = 0;
// 	while (row < 66)
// 	{
// 		col = 0;
// 		while (col < 66)
// 		{
// 			(img_matrix)[row][col]->a = (char)0;
// 			(img_matrix)[row][col]->r = (texture.matx)[row][col]->r;
// 			(img_matrix)[row][col]->g = (texture.matx)[row][col]->g;
// 			(img_matrix)[row][col]->b = (texture.matx)[row][col]->b;
// 			col = col + 1;

// 		}
// 		row = row + 1;
// 	}
// }


void	render_menu(t_data *data)
{
	(void) data;
	int	x;
	int	y;

	x = (SCREEN_WIDTH - data->util.pause.width) / 2;
	y = (SCREEN_HEIGHT - data->util.pause.height) / 4;
	//copy_the_matrix(data->video.img_matrix, data->util.pause);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->util.pause.img_header, x, y);
}