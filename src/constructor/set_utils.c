#include "constructor.h"

static int	set_map_scale(t_data *data)
{
	int	size_x;
	int	size_y;
	int	factor;
	int	*arr;

	size_y = 0;
	size_x = 0;
	arr = line_lengths(data->map.bit_map);
	while (arr[size_y])
	{
		if (arr[size_y] > size_x)
			size_x = arr[size_y];
		size_y++;
	}
	free(arr);
	factor = ((SCREEN_WIDTH * 0.6) / size_x);
	if ((((SCREEN_HEIGHT * 0.6) / size_y)) < factor)
		factor = (((SCREEN_HEIGHT * 0.6) / size_y));
	data->util.map_offset_x = (SCREEN_WIDTH - (size_x * factor)) / 2;
	data->util.map_offset_y = (SCREEN_HEIGHT - (size_y * factor)) / 2;
	return (factor);
}

/*
	Sets additional data like minimap color
	To avoid additional loops in video render
*/
t_utils	set_utils(t_data *data)
{
	t_utils	utils;

	utils.minimap[0] = set_color(0, 40, 40, 40);
	utils.minimap[1] = set_color(0, 120, 120, 120);
	utils.minimap[2] = set_color(0, 101, 67, 33);
	utils.minimap[3] = set_color(0, 255, 0, 0);
	utils.minimap[4] = set_color(0, 0, 0, 0);
	utils.map_scale = set_map_scale(data);
	utils.minimap_state = 1;
	utils.game_state = 1;
	utils.pause = open_texture_xpm2(data, "./assets/utils/img_pause.xpm");
	utils.time_stamp = set_time();
	utils.map_offset_x = data->util.map_offset_x;
	utils.map_offset_y = data->util.map_offset_y;
	return (utils);
}
