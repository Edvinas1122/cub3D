#include "display.h"

// static void	copy_the_matrix(t_color ***img_matrix, t_texture texture)
// {
// 	int	row;
// 	int	col;
// 	// double	vertical_factor;
// 	// double	horizontal_factor;

// 	printf("\n%d\n", texture.height);
// 	printf("\n%d\n", texture.width);
// 	// vertical_factor = (double)SCREEN_WIDTH / texture.width;
// 	// horizontal_factor = (double)SCREEN_HEIGHT / texture.height;
// 	row = 0;
// 	while (row < 204)
// 	{
// 		col = 0;
// 		while (col < 204)
// 		{
// 			(img_matrix)[row][col]->a = (char)0;
// 			(img_matrix)[row][col]->r = (texture.matx)[col][row]->r;
// 			(img_matrix)[row][col]->g = (texture.matx)[col][row]->g;
// 			(img_matrix)[row][col]->b = (texture.matx)[col][row]->b;
// 			col = col + 1;

// 		}
// 		row = row + 1;
// 	}
// }


void	render_menu(t_data *data)
{
	(void) data;
	copy_the_matrix(data->video.img_matrix, data->util.pause);
	

}