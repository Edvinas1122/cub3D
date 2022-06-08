#include "display.h"

/*
	Renders display
*/
int	render_display(t_data *data)
{
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.video.img, 0, 0);
}