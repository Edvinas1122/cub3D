#include "display.h"

/*
	Renders display
	Game engine
*/
int	render_display(t_data *data)
{
	if (data->util.game_state == 1)
	{
		render_fov_view(data);
		display_minimap(data);
		
	}
	else if (data->util.game_state == 0)
	{
		data->util.game_state = 2;
		color_the_matrix(data->video.img_matrix, 85, 80, 85);
	}
	else if (data->util.game_state == 2)
		render_menu(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->video.img, 0, 0);
	return (0);
}
