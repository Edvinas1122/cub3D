#include "display.h"

// static int	column_sample_offset(int width, t_raycast *raycast)
// {
// 	int	x;

// 	x = (int)(raycast->impact->x) % width; 
// 	return (x);
// }

// /*
// 	Provides texture facing direction
// */
// static int	texture_direction(t_raycast *raycast, t_vect pos)
// {
// 	(void) raycast;
// 	(void) pos;
// 	return (0);
// }

/*
	Returns pixel sampled from texture based on raycast data
*/
t_color	sample_texture_pixel(t_data	*data, t_raycast *raycast, t_wall *wall)
{
	int x;

	x = 0;
	x++;
	(void) raycast;
	(void) wall;
	//texture_direction(raycast, data->player.pos);
	//x = column_sample_offset(data->map.north.width, raycast);
	return (*(data->map.north.matx[10][10]));
}