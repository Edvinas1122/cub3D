#include "display.h"

/*
	Renders display
*/
int	render_display(t_data *data)
{
	//color_the_matrix(data->video.img_matrix, 255, 0, 0);
	render_fov_view(data);
	display_minimap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->video.img, 0, 0);

	return (0);
}
