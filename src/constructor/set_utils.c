#include "constructor.h"

static int	set_minimap_scale(t_data *data)
{
	int	size_x;
	int	size_y;
	int factor;
	int	*arr;

	size_y = 0;
	size_x = 0;
	arr = line_lenghts(data->map.bit_map);
	while (arr[size_y])
	{
		if (arr[size_y] > size_x)
			size_x = arr[size_y];
		size_y++;
	}
	free(arr);
	factor = (SCREEN_WIDTH / size_x);
	if (((SCREEN_HEIGHT / size_y)) < factor)
		factor = ((SCREEN_HEIGHT / size_y));
	return (factor/4);
}

/*
	Sets additional data like minimap color
	To avoid additional loops in video render
*/
t_utils set_utils(t_data *data)
{
	t_utils utils;

	(void) data;
	utils.minimap[0] = set_color(0, 40, 40, 40);
	utils.minimap[1] = set_color(0, 120, 120, 120);
	utils.minimap[2] = set_color(0, 255, 0, 0);
	utils.minimap_size = set_minimap_scale(data);
	printf("\n%i\n", utils.minimap_size);
	return (utils);
}
