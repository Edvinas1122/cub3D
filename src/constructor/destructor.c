#include "constructor.h"

void	destructor(t_data *data)
{
	if (data->map.bit_map)
		free(data->map.bit_map);
	exit(0);
}
