#include "constructor.h"

void	destructor(t_data *data)
{
	if (data->map.bit_map)
		free(data->map.bit_map);
	// if (data->mlx.ptr)
	// 		mlx_destroy_window(data->mlx, data->);
	exit(0);
}
