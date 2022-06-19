#include "display.h"

/*
	Object for pause menu
	Data voided for future implamentations
*/
void	render_menu(t_data *data)
{
	int		x;
	int		y;

	(void)data;
	x = (SCREEN_WIDTH - data->util.pause.width) / 2;
	y = (SCREEN_HEIGHT - data->util.pause.height) / 4;
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
		data->util.pause.img_header, x, y);
}
