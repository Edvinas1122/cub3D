#include "display.h"

static void	set_wall_data(t_wall *wall, t_raycast *raycast)
{
	wall->offset = 0;
	wall->size = SCREEN_HEIGHT/(raycast->distance/TILE_SIZE);
	wall->y = 0;
	wall->start = SCREEN_HEIGHT/2.0 - (wall->size)/2;
	if (wall->start < 0)
	{
		wall->offset = wall->start * -1;
		wall->start = 0;
	}
	wall->end = wall->size + wall->start;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
}

/*
	Draws vertical pixel line using raycast data
	top portion - ceiling , middle - wall, bottom - floor
*/
void	draw_vertical_line(t_data *data, t_raycast *raycast)
{
	t_wall	wall;

	set_wall_data(&wall, raycast);
	while (wall.y < wall.start)
	{
		pixel_put(data->video.img_matrix, data->map.ceiling, raycast->v_line_ct, wall.y);
		wall.y++;
	}
	draw_wall_line(data, raycast, &wall);
	while (wall.y < SCREEN_HEIGHT)
	{
		pixel_put(data->video.img_matrix, data->map.floor, raycast->v_line_ct, wall.y);
		wall.y++;
	}
}
