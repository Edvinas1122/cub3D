#include "../cube3d.h"

static void	set_time_stamp(t_data *data)
{
	double			time_diff;
	double			move_factor;

	data->util.old_time_stamp = data->util.time_stamp;
	data->util.time_stamp = set_time();
	time_diff = data->util.time_stamp - data->util.old_time_stamp;
	if (time_diff <= 0)
		return ;
	move_factor = (double)(MOVE_DISTANCE) * (time_diff /33333.0);
	// printf("\nOne frame time: %f\n", time_diff);
	// printf("\nFPS: %f\n", 1000000 / time_diff);
	// printf("\nMove factor: %f\n", move_factor);
	data->util.move_factor = move_factor;
}

static void	update_doors(t_data *data)
{
	int	i;

	i = 0;
	while (data->doors[i])
	{
		if ((*data->doors[i]).closed_percentage == 100)
			(*data->doors[i]).moving = -10;
		if ((*data->doors[i]).closed_percentage == 0)
			(*data->doors[i]).moving = 10;
		(*data->doors[i]).closed_percentage += (*data->doors[i]).moving;
		if ((*data->doors[i]).closed_percentage > 100)
			(*data->doors[i]).closed_percentage = 100;
		if ((*data->doors[i]).closed_percentage < 0)
			(*data->doors[i]).closed_percentage = 0;
		i++;
	}
}

int	engine(t_data *data)
{
	if (data->count++ > 10000000)
		data->count = 0;
	set_time_stamp(data);
	player_movement(data);
	update_doors(data);
	render_display(data);
	return (0);
}
