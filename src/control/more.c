#include "control.h"

void	pop_minimap(t_data *data)
{
	static int	iteration;

	if (!iteration)
	{
		data->util.minimap_size *= 4;
		iteration = 1;
	}
	else
	{
		data->util.minimap_size /= 4;
		iteration = 0;
	}
}