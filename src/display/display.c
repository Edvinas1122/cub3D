#include "display.h"

// static void	display_hud(t_data *data)
// {

// }

/*
	Renders display
*/
int	render_display(t_data *data)
{
	struct timeval	time;
	long			timestamp;
	long			difference;

	gettimeofday(&time, NULL);
	timestamp = time.tv_usec;
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
	gettimeofday(&time, NULL);
	difference = time.tv_usec - timestamp;
	if (difference > 0)
		data->util.frame_rate = 1000000 / (difference);
	//mlx_string_put();
	return (0);
}
