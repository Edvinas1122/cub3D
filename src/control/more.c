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

void	close_win(t_data *data)
{
	ft_putstr_fd("Exiting program\n", 1);
	destructor(data);
}
